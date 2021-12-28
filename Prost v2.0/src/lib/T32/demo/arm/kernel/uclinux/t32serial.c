/* serial port driver for the TRACE32 Terminal Emulation
 *
 * Copyright (C) 2002  Rudi Dienstbeck (Rudi.Dienstbeck@Lauterbach.com)
 *
 * Used with buffered communication.
 * If used with dual port memory (ICE/FIRE/SIM), use
 * TERM.Protocol BufferE
 * If used with ICD / no dual port memory, use
 * TERM.Protocol BufferC T32PUTBUF
 * Then open the terminal with
 * TERM T32OUTBUF T32INBUF
 */

#include <linux/config.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/serial.h>
#include <linux/errno.h>
#include <linux/signal.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/interrupt.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/config.h>
#include <linux/major.h>
#include <linux/string.h>
#include <linux/fcntl.h>
#include <linux/mm.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/console.h>

//#include <asm/io.h>
//#include <asm/irq.h>
#include <asm/system.h>
#include <asm/segment.h>
#include <asm/bitops.h>
#include <asm/delay.h>
#include <asm/uaccess.h>

#ifdef SERIAL_XMIT_SIZE
  #undef SERIAL_XMIT_SIZE
#endif
#define SERIAL_XMIT_SIZE	128     // MUST be power of 2!  PAGE_SIZE
#define RX_SERIAL_SIZE		250

#define S_INITIALIZED     0x80000000 /* Serial port was initialized */
#define RS_EVENT_WRITE_WAKEUP   0
#define S_USR_MASK 0x0430        /* Legal flags that non-privileged */
#define S_FLAGS  0x0FFF  /* Possible legal S flags */
#define S_CLOSING                0x08000000 /* Serial port is closing */
#define S_CLOSING_WAIT_NONE      65535
#define S_NORMAL_ACTIVE  0x20000000 /* Normal device is active */
#define S_CALLOUT_ACTIVE 0x40000000 /* Call out device is active */
#define S_SESSION_LOCKOUT 0x0100 /* Lock out cua opens based on session */
#define S_PGRP_LOCKOUT    0x0200 /* Lock out cua opens based on pgrp */
#define S_SPLIT_TERMIOS 0x0008 /* Separate termios for dialin/callout */

/* serial subtype definitions */
#define SERIAL_TYPE_NORMAL	1
#define SERIAL_TYPE_CALLOUT	2
#define SERIAL_MAGIC 0x5301

/* number of characters left in xmit buffer before we ask for more */
#define WAKEUP_CHARS 250

/* Debugging... */
#define SERIAL_DEBUG_OPEN

#ifndef MIN
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#endif


volatile char T32OUTBUF[256], T32INBUF[256];


struct t32_serial {
    volatile char* incount;
    volatile char* outcount;
    volatile char* inbuf;
    volatile char* outbuf;
    
	char is_cons;       /* Is this our console. */

	int			magic;
	int			flags; 		/* defined in tty.h */
	int			type; 		/* UART type */
	struct tty_struct 	*tty;
	int			close_delay;
	unsigned short		closing_wait;
	unsigned long		event;
	int			line;
	int			count;	    /* # of fd on device */
	int			blocked_open; /* # of blocked opens */
	long			session; /* Session of opening process */
	long			pgrp; /* pgrp of opening process */
	unsigned char 		*xmit_buf;
	unsigned char 		*rx_buf;
	int			xmit_head;
	int			xmit_tail;
	int			xmit_cnt;
	struct tq_struct	tqueue;
	struct tq_struct	tqueue_hangup;
	struct termios		normal_termios;
	struct termios		callout_termios;
	wait_queue_head_t	open_wait;
	wait_queue_head_t	close_wait;
};

static struct t32_serial t32_info;

/*
 * tmp_buf is used as a temporary buffer by serial_write.  We need to
 * lock it in case the memcpy_fromfs blocks while swapping in a page,
 * and some other program tries to do a serial write at the same time.
 * Since the lock will only come under contention when the system is
 * swapping and available memory is low, it makes sense to share one
 * buffer across all the serial ports, since it significantly saves
 * memory if large numbers of serial ports are open.
 */
static unsigned char tmp_buf[SERIAL_XMIT_SIZE];	/* This is cheating */
DECLARE_MUTEX(tmp_buf_sem);

static unsigned char rx_buf1[RX_SERIAL_SIZE];

/* Console hooks... */
struct t32_serial *t32_consinfo = 0;

DECLARE_TASK_QUEUE(tq_t32_serial);

static struct tq_struct serialpoll;
static struct tty_driver serial_driver, callout_driver;
static int serial_refcount;

static void serpoll(void *data);

static struct tty_struct *serial_table[1];
static struct termios *serial_termios[1];
static struct termios *serial_termios_locked[1];

static char prompt0;
static void xmit_char(struct t32_serial *info, char ch);
static void xmit_string(struct t32_serial *info, char *p, int len);
static void wait_EOT(struct t32_serial *info);

static void tx_stop  (struct t32_serial *info);
static void tx_start (struct t32_serial *info);
static void rx_stop  (struct t32_serial *info);
static void rx_start (struct t32_serial *info);
static void rs_interrupt(struct t32_serial *info);
static void handle_termios_tcsets(struct termios * ptermios, struct t32_serial * ptty);

static void  tx_stop(struct t32_serial *info)
{
}

static void  tx_start(struct t32_serial *info)
{
}

static void  rx_stop(struct t32_serial *info)
{
}

static void  rx_start(struct t32_serial *info)
{
    serialpoll.data = (void*) info;
	queue_task (&serialpoll, &tq_timer);
}

static inline int serial_paranoia_check(struct t32_serial *info,
					dev_t device, const char *routine)
{
#ifdef SERIAL_PARANOIA_CHECK
	static const char *badmagic =
		"Warning: bad magic number for serial struct (%d, %d) in %s\n";
	static const char *badinfo =
		"Warning: null atmel_serial struct for (%d, %d) in %s\n";

	if (!info) {
		printk(badinfo, MAJOR(device), MINOR(device), routine);
		return 1;
	}
	if (info->magic != SERIAL_MAGIC) {
		printk(badmagic, MAJOR(device), MINOR(device), routine);
		return 1;
	}
#endif
	return 0;
}

/*
 * ------------------------------------------------------------
 * rs_stop() and rs_start()
 *
 * This routines are called before setting or resetting tty->stopped.
 * They enable or disable transmitter interrupts, as necessary.
 * ------------------------------------------------------------
 */
static void rs_stop(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;
	unsigned long flags;

	if (serial_paranoia_check(info, tty->device, "rs_stop"))
		return;

	save_flags(flags);
	cli();
	tx_stop(info);
	rx_stop(info);
	restore_flags(flags);
}

static void rs_put_char(struct t32_serial *info, char ch)
{
	int flags = 0;

	save_flags(flags);
	cli();
	xmit_char(info, ch);
	wait_EOT(info);
	restore_flags(flags);
}

static void rs_start(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;
	unsigned long flags;

	if (serial_paranoia_check(info, tty->device, "rs_start"))
		return;

	save_flags(flags);
	cli();
	tx_start(info);
	rx_start(info);
	restore_flags(flags);
}


/*
 * ----------------------------------------------------------------------
 *
 * Here starts the interrupt handling routines.  All of the following
 * subroutines are declared as inline and are folded into
 * rs_interrupt().  They were separated out for readability's sake.
 *
 * Note: rs_interrupt() is a "fast" interrupt, which means that it
 * runs with interrupts turned off.  People who may want to modify
 * rs_interrupt() should try to keep the interrupt handler as fast as
 * possible.  After you are done making modifications, it is not a bad
 * idea to do:
 *
 * gcc -S -DKERNEL -Wall -Wstrict-prototypes -O6 -fomit-frame-pointer serial.c
 *
 * and look at the resulting assembly code in serial.s.
 *
 * -----------------------------------------------------------------------
 */

/*
 * This routine is used by the interrupt handler to schedule
 * processing in the software interrupt portion of the driver.
 */
static  void rs_sched_event(struct t32_serial *info, int event)
{
	info->event |= 1 << event;
	queue_task(&info->tqueue, &tq_t32_serial);
	mark_bh(SERIAL_BH);
}


static  void receive_chars(struct t32_serial *info)
{
	unsigned char ch;
	int count;

#if 0
	// hack to receive chars by polling from anywhere
	struct tty_struct *tty = info1->tty;

	if (!(info->flags & S_INITIALIZED))
		return;
#else
	struct tty_struct *tty = info->tty;

	if (!(info->flags & S_INITIALIZED))
		return;
#endif

	count = *info->incount;
	
	if (!count) {
		return;
	}

	ch = info->inbuf[0];
	if (info->is_cons) {
		if (ch == 0x10) {	/* ^P */
			show_state();
			show_free_areas();
			show_buffers();
			//show_net_buffers();
			return;
		} else if (ch == 0x12) {	/* ^R */
			//hard_reset_now();
			return;
		}
		/* It is a 'keyboard interrupt' ;-) */
		// wake_up(&keypress_wait);
	}

	if (!tty)
		goto clear_and_exit;

	if (tty->flip.count >= TTY_FLIPBUF_SIZE)
		queue_task(&tty->flip.tqueue, &tq_timer);

	if ((count + tty->flip.count) >= TTY_FLIPBUF_SIZE) {
		serialpoll.data = (void *) info;
		queue_task(&serialpoll, &tq_timer);
	}
	memset(tty->flip.flag_buf_ptr, 0, count);
	memcpy(tty->flip.char_buf_ptr, (char*) info->inbuf, count);
	tty->flip.char_buf_ptr += count;
	tty->flip.count += count;

	queue_task(&tty->flip.tqueue, &tq_timer);

  clear_and_exit:
    *info->incount = 0;
	return;
}

static  void transmit_chars(struct t32_serial *info)
{
	if ((info->xmit_cnt <= 0) || info->tty->stopped) {
		/* That's peculiar... */
		tx_stop(info);
		goto clear_and_return;
	}

	if (info->xmit_tail + info->xmit_cnt < SERIAL_XMIT_SIZE) {
		xmit_string(info, info->xmit_buf + info->xmit_tail,
					info->xmit_cnt);
		info->xmit_tail =
			(info->xmit_tail + info->xmit_cnt) & (SERIAL_XMIT_SIZE - 1);
		info->xmit_cnt = 0;
	} else {
		xmit_string(info, info->xmit_buf + info->xmit_tail,
					SERIAL_XMIT_SIZE - info->xmit_tail);
		//xmit_string(info, info->xmit_buf, info->xmit_tail + info->xmit_cnt - SERIAL_XMIT_SIZE);
		info->xmit_cnt =
			info->xmit_cnt - (SERIAL_XMIT_SIZE - info->xmit_tail);
		info->xmit_tail = 0;
	}

	if (info->xmit_cnt < WAKEUP_CHARS)
		rs_sched_event(info, RS_EVENT_WRITE_WAKEUP);

	if (info->xmit_cnt <= 0) {
		//tx_stop(info);
		goto clear_and_return;
	}

  clear_and_return:
	return;
}


/*
 * This is the serial driver's generic interrupt routine
 */

static void rs_interrupt(struct t32_serial *info)
{
	if (*info->incount)     // characters available
	{
		receive_chars(info);
	}
	if (!*info->outcount)   // output channel free
	{
		transmit_chars(info);
	}

	serialpoll.data = (void *) info;
	queue_task (&serialpoll, &tq_timer);

	return;
}


static void serpoll(void *data)
{
	struct t32_serial *info = data;

	rs_interrupt(info);
}

/*
 * -------------------------------------------------------------------
 * Here ends the serial interrupt routines.
 * -------------------------------------------------------------------
 */

/*
 * This routine is used to handle the "bottom half" processing for the
 * serial driver, known also the "software interrupt" processing.
 * This processing is done at the kernel interrupt level, after the
 * rs_interrupt() has returned, BUT WITH INTERRUPTS TURNED ON.  This
 * is where time-consuming activities which can not be done in the
 * interrupt driver proper are done; the interrupt driver schedules
 * them using rs_sched_event(), and they get done here.
 */
static void do_serial_bh(void)
{
	run_task_queue(&tq_t32_serial);
}

static void do_softint(void *private_)
{
	struct t32_serial *info = (struct t32_serial *) private_;
	struct tty_struct *tty;

	tty = info->tty;
	if (!tty)
		return;
		
#if 0 	// FIXME - CHECK
	if (clear_bit(RS_EVENT_WRITE_WAKEUP, &info->event)) {
		if ((tty->flags & (1 << TTY_DO_WRITE_WAKEUP)) &&
			tty->ldisc.write_wakeup) (tty->ldisc.write_wakeup) (tty);
		wake_up_interruptible(&tty->write_wait);
	}
#endif
}

/*
 * This routine is called from the scheduler tqueue when the interrupt
 * routine has signalled that a hangup has occurred.  The path of
 * hangup processing is:
 *
 * 	serial interrupt routine -> (scheduler tqueue) ->
 * 	do_serial_hangup() -> tty->hangup() -> rs_hangup()
 *
 */
static void do_serial_hangup(void *private_)
{
	struct t32_serial *info = (struct t32_serial *) private_;
	struct tty_struct *tty;

	tty = info->tty;
	if (!tty)
		return;

	tty_hangup(tty);
}



static void wait_EOT(struct t32_serial *info)
{
	// wait until all chars sent FIXME - is this sane ?
	while (*info->outcount) {
	}
}

static int startup(struct t32_serial *info)
{
	unsigned long flags;

	if (info->flags & S_INITIALIZED)
		return 0;

	if (!info->xmit_buf) {
		info->xmit_buf = (unsigned char *) get_free_page(GFP_KERNEL);
		if (!info->xmit_buf)
			return -ENOMEM;
	}
	if (!info->rx_buf) {
	    //info->rx_buf = (unsigned char *) get_free_page(GFP_KERNEL);
		//info->rx_buf = rx_buf1;
		if (!info->rx_buf)
			return -ENOMEM;
	}
	save_flags(flags);
	cli();
#ifdef SERIAL_DEBUG_OPEN
	printk("starting up ttyS%d...\n", info->line);
#endif
	/*
	 * Clear the FIFO buffers and disable them
	 */

	if (info->tty)
		clear_bit(TTY_IO_ERROR, &info->tty->flags);
	info->xmit_cnt = info->xmit_head = info->xmit_tail = 0;

	/*
	 * and set the speed of the serial port
	 */

	info->flags |= S_INITIALIZED;
	restore_flags(flags);
	return 0;
}

/*
 * This routine will shutdown a serial port; 
 */
static void shutdown(struct t32_serial *info)
{
	unsigned long flags;

	rx_stop(info);		/* All off! */
	if (!(info->flags & S_INITIALIZED))
		return;

#ifdef SERIAL_DEBUG_OPEN
	printk("Shutting down TRACE32 serial port....\n");
#endif

	save_flags(flags);
	cli();						/* Disable interrupts */

	if (info->xmit_buf) {
		free_page((unsigned long) info->xmit_buf);
		info->xmit_buf = 0;
	}

	if (info->tty)
		set_bit(TTY_IO_ERROR, &info->tty->flags);

	info->flags &= ~S_INITIALIZED;
	restore_flags(flags);
}

static void xmit_char(struct t32_serial *info, char ch)
{
	prompt0 = ch;
	xmit_string(info, &prompt0, 1);
}

static void xmit_string(struct t32_serial *info, char *p, int len)
{
    while (*info->outcount);
    memcpy ((char*) info->outbuf, p, len);
    *info->outcount = len;
}

/*
 * t32_console_print is registered for printk.
 */
int t32_console_initialized;

static void init_console(struct t32_serial *info)
{
	memset(info, 0, sizeof(struct t32_serial));

	info->tty = 0;
	info->is_cons = 1;
	t32_console_initialized = 1;
}


void console_print_t32(const char *p)
{
	char c;
	struct t32_serial *info;

	info = &t32_info;

	if (!t32_console_initialized) {
		init_console(info);
		tx_stop(info);
		rx_stop(info);
		tx_start(info);
		rx_start(info);
	}

	while ((c = *(p++)) != 0) {
		if (c == '\n')
			rs_put_char(info, '\r');
		rs_put_char(info, c);
	}

    // rs_fair_output(info);

	return;
}

static void rs_set_ldisc(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;

	if (serial_paranoia_check(info, tty->device, "rs_set_ldisc"))
		return;

	info->is_cons = (tty->termios->c_line == N_TTY);

	printk("ttyS%d console mode %s\n", info->line,
		   info->is_cons ? "on" : "off");
}

static void rs_flush_chars(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;

	if (serial_paranoia_check(info, tty->device, "rs_flush_chars"))
		return;

	for (;;) {
		if (info->xmit_cnt <= 0 || tty->stopped || tty->hw_stopped ||
			!info->xmit_buf) return;

		xmit_string(info, info->xmit_buf + info->xmit_tail,	info->xmit_cnt);
		info->xmit_tail = (info->xmit_tail + info->xmit_cnt) & (SERIAL_XMIT_SIZE - 1);
		info->xmit_cnt = 0;
	}

	wait_EOT(info);
}

extern void console_printn(const char *b, int count);

static int rs_write(struct tty_struct *tty, int from_user,
					const unsigned char *buf, int count)
{
	int c, total = 0;
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;
	unsigned long flags;

	if (serial_paranoia_check(info, tty->device, "rs_write"))
		return 0;

	if (!tty || !info->xmit_buf)
		return 0;

	save_flags(flags);
	while (1) {
		cli();
		c = MIN(count, MIN(SERIAL_XMIT_SIZE - info->xmit_cnt - 1,
						   SERIAL_XMIT_SIZE - info->xmit_head));
		if (c <= 0)
			break;

		if (from_user) {
			down(&tmp_buf_sem);
			copy_from_user(tmp_buf, buf, c);
			memcpy(info->xmit_buf + info->xmit_head, tmp_buf, c);
			up(&tmp_buf_sem);
		} else {
			memcpy(info->xmit_buf + info->xmit_head, buf, c);
		}
		info->xmit_head = (info->xmit_head + c) & (SERIAL_XMIT_SIZE - 1);
		info->xmit_cnt += c;
		restore_flags(flags);
		buf += c;
		count -= c;
		total += c;
	}

	if (info->xmit_cnt && !tty->stopped && !tty->hw_stopped) {
		/* Enable transmitter */

		cli();
		/*printk("Enabling transmitter\n"); */

			if (info->xmit_cnt) {
				/* Send char */
				wait_EOT(info);
				if (info->xmit_tail + info->xmit_cnt < SERIAL_XMIT_SIZE) {
					xmit_string(info, info->xmit_buf + info->xmit_tail,
								info->xmit_cnt);
					info->xmit_tail =
						(info->xmit_tail +
						 info->xmit_cnt) & (SERIAL_XMIT_SIZE - 1);
					info->xmit_cnt = 0;
				} else {
					xmit_string(info, info->xmit_buf + info->xmit_tail,
								SERIAL_XMIT_SIZE - info->xmit_tail);
					info->xmit_cnt =
						info->xmit_cnt - (SERIAL_XMIT_SIZE - info->xmit_tail);
					info->xmit_tail = 0;
				}
			}
	} else {
		/*printk("Skipping transmit\n"); */
	}

	tx_start(0);

	restore_flags(flags);
	return total;
}

static int rs_write_room(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;
	int ret;

	if (serial_paranoia_check(info, tty->device, "rs_write_room"))
		return 0;
	ret = SERIAL_XMIT_SIZE - info->xmit_cnt - 1;
	if (ret < 0)
		ret = 0;
	return ret;
}

static int rs_chars_in_buffer(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;

	if (serial_paranoia_check(info, tty->device, "rs_chars_in_buffer"))
		return 0;
	return info->xmit_cnt;
}

static void rs_flush_buffer(struct tty_struct *tty)
{
	unsigned long flags;
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;

	if (serial_paranoia_check(info, tty->device, "rs_flush_buffer"))
		return;
	save_flags(flags);
	cli();
	info->xmit_cnt = info->xmit_head = info->xmit_tail = 0;
	restore_flags(flags);
	wake_up_interruptible(&tty->write_wait);
	if ((tty->flags & (1 << TTY_DO_WRITE_WAKEUP)) &&
		tty->ldisc.write_wakeup) (tty->ldisc.write_wakeup) (tty);
}

/*
 * ------------------------------------------------------------
 * rs_throttle()
 *
 * This routine is called by the upper-layer tty layer to signal that
 * incoming characters should be throttled.
 * ------------------------------------------------------------
 */
static void rs_throttle(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;

#ifdef SERIAL_DEBUG_THROTTLE
	char buf[64];

	printk("throttle %s: %d....\n", _tty_name(tty, buf),
		   tty->ldisc.chars_in_buffer(tty));
#endif

	if (serial_paranoia_check(info, tty->device, "rs_throttle"))
		return;
}

static void rs_unthrottle(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;

#ifdef SERIAL_DEBUG_THROTTLE
	char buf[64];

	printk("unthrottle %s: %d....\n", _tty_name(tty, buf),
		   tty->ldisc.chars_in_buffer(tty));
#endif

	if (serial_paranoia_check(info, tty->device, "rs_unthrottle"))
		return;
}

/*
 * ------------------------------------------------------------
 * rs_ioctl() and friends
 * ------------------------------------------------------------
 */

static int get_serial_info(struct t32_serial *info,
						   struct serial_struct *retinfo)
{
	struct serial_struct tmp;

	if (!retinfo)
		return -EFAULT;
	memset(&tmp, 0, sizeof(tmp));
	tmp.type = info->type;
	tmp.line = info->line;
	tmp.irq = 0;
	tmp.port = 0;
	tmp.flags = info->flags;
	tmp.baud_base = 0;
	tmp.close_delay = info->close_delay;
	tmp.closing_wait = info->closing_wait;
	tmp.custom_divisor = 0;
	copy_to_user(retinfo, &tmp, sizeof(*retinfo));
	return 0;
}

static int set_serial_info(struct t32_serial *info,
						   struct serial_struct *new_info)
{
	struct serial_struct new_serial;
	struct t32_serial old_info;
	int retval = 0;

	if (!new_info)
		return -EFAULT;
	copy_from_user(&new_serial, new_info, sizeof(new_serial));
	old_info = *info;

	if (!suser()) {
		if ((new_serial.type != info->type) ||
			(new_serial.close_delay != info->close_delay) ||
			((new_serial.flags & ~S_USR_MASK) !=
			 (info->flags & ~S_USR_MASK))) return -EPERM;
		info->flags = ((info->flags & ~S_USR_MASK) |
					   (new_serial.flags & S_USR_MASK));
		goto check_and_exit;
	}

	if (info->count > 1)
		return -EBUSY;

	/*
	 * OK, past this point, all the error checking has been done.
	 * At this point, we start making changes.....
	 */

	info->flags = ((info->flags & ~S_FLAGS) |
				   (new_serial.flags & S_FLAGS));
	info->type = new_serial.type;
	info->close_delay = new_serial.close_delay;
	info->closing_wait = new_serial.closing_wait;

  check_and_exit:
	//retval = startup(info);
	retval = 0;
	return retval;
}

/*
 * get_lsr_info - get line status register info
 *
 * Purpose: Let user call ioctl() to get info when the UART physically
 * 	    is emptied.  On bus types like RS485, the transmitter must
 * 	    release the bus after transmitting. This must be done when
 * 	    the transmit shift register is empty, not be done when the
 * 	    transmit holding register is empty.  This functionality
 * 	    allows an RS485 driver to be written in user space.
 */
static int get_lsr_info(struct t32_serial *info, unsigned int *value)
{
	unsigned char status;

	cli();
	status = 0;
	sti();
	put_user(status, value);
	return 0;
}

/*
 * This routine sends a break character out the serial port.
 */
static void send_break(struct t32_serial *info, int duration)
{
	current->state = TASK_INTERRUPTIBLE;
}

static int rs_ioctl(struct tty_struct *tty, struct file *file,
					unsigned int cmd, unsigned long arg)
{
	int error;
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;
	int retval;

	if (serial_paranoia_check(info, tty->device, "rs_ioctl"))
		return -ENODEV;

	if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
		(cmd != TIOCSERCONFIG) && (cmd != TIOCSERGWILD) &&
		(cmd != TIOCSERSWILD) && (cmd != TIOCSERGSTRUCT)) {
		if (tty->flags & (1 << TTY_IO_ERROR))
			return -EIO;
	}

	switch (cmd) {
	case TCSBRK:				/* SVID version: non-zero arg --> no break */
		retval = tty_check_change(tty);
		if (retval)
			return retval;
		tty_wait_until_sent(tty, 0);
		if (!arg)
			send_break(info, HZ / 4);	/* 1/4 second */
		return 0;
	case TCSBRKP:				/* support for POSIX tcsendbreak() */
		retval = tty_check_change(tty);
		if (retval)
			return retval;
		tty_wait_until_sent(tty, 0);
		send_break(info, arg ? arg * (HZ / 10) : HZ / 4);
		return 0;
	case TIOCGSOFTCAR:
		error = verify_area(VERIFY_WRITE, (void *) arg, sizeof(long));

		if (error)
			return error;
		put_user(C_CLOCAL(tty) ? 1 : 0, (unsigned long *) arg);
		return 0;
	case TIOCSSOFTCAR:
		arg = get_user(arg,(unsigned long *) arg);
		tty->termios->c_cflag = ((tty->termios->c_cflag & ~CLOCAL) | (arg ? CLOCAL : 0));
		return 0;
	case TIOCGSERIAL:
		error = verify_area(VERIFY_WRITE, (void *) arg, sizeof(struct serial_struct));
		if (error)
			return error;
		return get_serial_info(info, (struct serial_struct *) arg);
	case TIOCSSERIAL:
		return set_serial_info(info, (struct serial_struct *) arg);
	case TIOCSERGETLSR:		/* Get line status register */
		error = verify_area(VERIFY_WRITE, (void *) arg,
			sizeof(unsigned int));
		if (error)
			return error;
		else
			return get_lsr_info(info, (unsigned int *) arg);

	case TIOCSERGSTRUCT:
		error = verify_area(VERIFY_WRITE, (void *) arg,
			sizeof(struct t32_serial));
		if (error)
			return error;
		copy_to_user((struct atmel_serial *) arg, info,
			sizeof(struct t32_serial));
		return 0;

	case TCSETS:	
		handle_termios_tcsets((struct termios *)arg, info);
		//		return set_serial_info(info, (struct serial_struct *) arg);
		break;	
	default:
		return -ENOIOCTLCMD;
	}
	return 0;
}

static void handle_termios_tcsets(struct termios * ptermios, struct t32_serial * pinfo )
{
	/*
	 * hmmmm....
	 */
	if (pinfo->tty->termios->c_cflag != ptermios->c_cflag)
		pinfo->tty->termios->c_cflag = ptermios->c_cflag;
}
	  
static void rs_set_termios(struct tty_struct *tty,
	struct termios *old_termios)
{
	// struct t32_serial *info = (struct t32_serial *) tty->driver_data;

	if (tty->termios->c_cflag == old_termios->c_cflag)
		return;

	if ((old_termios->c_cflag & CRTSCTS) &&
		!(tty->termios->c_cflag & CRTSCTS)) {
		tty->hw_stopped = 0;
		rs_start(tty);
	}

}

/*
 * ------------------------------------------------------------
 * rs_close()
 *
 * This routine is called when the serial port gets closed.  First, we
 * wait for the last remaining data to be sent.  Then, we unlink its
 * S structure from the interrupt chain if necessary, and we free
 * that IRQ if nothing is left in the chain.
 * ------------------------------------------------------------
 */
static void rs_close(struct tty_struct *tty, struct file *filp)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;
	unsigned long flags;

	if (!info || serial_paranoia_check(info, tty->device, "rs_close"))
		return;

	save_flags(flags);
	cli();

	if (tty_hung_up_p(filp)) {
		restore_flags(flags);
		return;
	}
#ifdef SERIAL_DEBUG_OPEN
	printk("rs_close ttyS%d, count = %d\n", info->line, info->count);
#endif
	if ((tty->count == 1) && (info->count != 1)) {
		/*
		 * Uh, oh.  tty->count is 1, which means that the tty
		 * structure will be freed.  Info->count should always
		 * be one in these conditions.  If it's greater than
		 * one, we've got real problems, since it means the
		 * serial port won't be shutdown.
		 */
		printk("rs_close: bad serial port count; tty->count is 1, "
			   "info->count is %d\n", info->count);
		info->count = 1;
	}
	if (--info->count < 0) {
		printk("rs_close: bad serial port count for ttyS%d: %d\n",
			   info->line, info->count);
		info->count = 0;
	}
	if (info->count) {
		restore_flags(flags);
		return;
	}

	info->flags |= S_CLOSING;
	/*
	 * Save the termios structure, since this port may have
	 * separate termios for callout and dialin.
	 */
	if (info->flags & S_NORMAL_ACTIVE)
		info->normal_termios = *tty->termios;
	if (info->flags & S_CALLOUT_ACTIVE)
		info->callout_termios = *tty->termios;
	/*
	 * Now we wait for the transmit buffer to clear; and we notify
	 * the line discipline to only process XON/XOFF characters.
	 */
	tty->closing = 1;
	if (info->closing_wait != S_CLOSING_WAIT_NONE)
		tty_wait_until_sent(tty, info->closing_wait);
	/*
	 * At this point we stop accepting input.  To do this, we
	 * disable the receive line status interrupts, and tell the
	 * interrupt driver to stop checking the data ready bit in the
	 * line status register.
	 */

	shutdown(info);
	if (tty->driver.flush_buffer)
		tty->driver.flush_buffer(tty);
	if (tty->ldisc.flush_buffer)
		tty->ldisc.flush_buffer(tty);
	tty->closing = 0;
	info->event = 0;
	info->tty = 0;
	if (tty->ldisc.num != ldiscs[N_TTY].num) {
		if (tty->ldisc.close)
			(tty->ldisc.close) (tty);
		tty->ldisc = ldiscs[N_TTY];
		tty->termios->c_line = N_TTY;
		if (tty->ldisc.open)
			(tty->ldisc.open) (tty);
	}
	if (info->blocked_open) {
		if (info->close_delay) {
			current->state = TASK_INTERRUPTIBLE;
			schedule_timeout(info->close_delay);
		}
		wake_up_interruptible(&info->open_wait);
	}
	info->flags &= ~(S_NORMAL_ACTIVE | S_CALLOUT_ACTIVE | S_CLOSING);
	wake_up_interruptible(&info->close_wait);
	restore_flags(flags);
}

/*
 * rs_hangup() --- called by tty_hangup() when a hangup is signaled.
 */
static void rs_hangup(struct tty_struct *tty)
{
	struct t32_serial *info = (struct t32_serial *) tty->driver_data;

	if (serial_paranoia_check(info, tty->device, "rs_hangup"))
		return;

	rs_flush_buffer(tty);
	shutdown(info);
	info->event = 0;
	info->count = 0;
	info->flags &= ~(S_NORMAL_ACTIVE | S_CALLOUT_ACTIVE);
	info->tty = 0;
	wake_up_interruptible(&info->open_wait);
}

/*
 * ------------------------------------------------------------
 * rs_open() and friends
 * ------------------------------------------------------------
 */
static int block_til_ready(struct tty_struct *tty, struct file *filp,
						   struct t32_serial *info)
{
	DECLARE_WAITQUEUE(wait, current); 
	int retval;
	int do_clocal = 0;

	/*
	 * If the device is in the middle of being closed, then block
	 * until it's done, and then try again.
	 */
	if (info->flags & S_CLOSING) {
		interruptible_sleep_on(&info->close_wait);
#ifdef SERIAL_DO_RESTART
		if (info->flags & S_HUP_NOTIFY)
			return -EAGAIN;
		else
			return -ERESTARTSYS;
#else
		return -EAGAIN;
#endif
	}

	/*
	 * If this is a callout device, then just make sure the normal
	 * device isn't being used.
	 */
	if (tty->driver.subtype == SERIAL_TYPE_CALLOUT) {
		if (info->flags & S_NORMAL_ACTIVE)
			return -EBUSY;
		if ((info->flags & S_CALLOUT_ACTIVE) &&
			(info->flags & S_SESSION_LOCKOUT) &&
			(info->session != current->session)) return -EBUSY;
		if ((info->flags & S_CALLOUT_ACTIVE) &&
			(info->flags & S_PGRP_LOCKOUT) &&
			(info->pgrp != current->pgrp)) return -EBUSY;
		info->flags |= S_CALLOUT_ACTIVE;
		return 0;
	}

	/*
	 * If non-blocking mode is set, or the port is not enabled,
	 * then make the check up front and then exit.
	 */
	if ((filp->f_flags & O_NONBLOCK) || (tty->flags & (1 << TTY_IO_ERROR))) {
		if (info->flags & S_CALLOUT_ACTIVE)
			return -EBUSY;
		info->flags |= S_NORMAL_ACTIVE;
		return 0;
	}

	if (info->flags & S_CALLOUT_ACTIVE) {
		if (info->normal_termios.c_cflag & CLOCAL)
			do_clocal = 1;
	} else {
		if (tty->termios->c_cflag & CLOCAL)
			do_clocal = 1;
	}

	/*
	 * Block waiting for the carrier detect and the line to become
	 * free (i.e., not in use by the callout).  While we are in
	 * this loop, info->count is dropped by one, so that
	 * rs_close() knows when to free things.  We restore it upon
	 * exit, either normal or abnormal.
	 */
	retval = 0;
	add_wait_queue(&info->open_wait, &wait);
#ifdef SERIAL_DEBUG_OPEN
	printk("block_til_ready before block: ttyS%d, count = %d\n",
		   info->line, info->count);
#endif
	info->count--;
	info->blocked_open++;
	while (1) {
		current->state = TASK_INTERRUPTIBLE;
		if (tty_hung_up_p(filp) || !(info->flags & S_INITIALIZED)) {
#ifdef SERIAL_DO_RESTART
			if (info->flags & S_HUP_NOTIFY)
				retval = -EAGAIN;
			else
				retval = -ERESTARTSYS;
#else
			retval = -EAGAIN;
#endif
			break;
		}
		if (!(info->flags & S_CALLOUT_ACTIVE) &&
			!(info->flags & S_CLOSING) && do_clocal)
			break;
		if (signal_pending(current)) {
			retval = -ERESTARTSYS;
			break;
		}
#ifdef SERIAL_DEBUG_OPEN
		printk("block_til_ready blocking: ttyS%d, count = %d\n",
			   info->line, info->count);
#endif
		schedule();
	}
	current->state = TASK_RUNNING;
	remove_wait_queue(&info->open_wait, &wait);
	if (!tty_hung_up_p(filp))
		info->count++;
	info->blocked_open--;
#ifdef SERIAL_DEBUG_OPEN
	printk("block_til_ready after blocking: ttyS%d, count = %d\n",
		   info->line, info->count);
#endif
	if (retval)
		return retval;
	info->flags |= S_NORMAL_ACTIVE;
	serialpoll.data = (void *) info;
	queue_task(&serialpoll, &tq_timer);
	return 0;
}

/*
 * This routine is called whenever a serial port is opened.  It
 * enables interrupts for a serial port, linking in its S structure into
 * the IRQ chain.   It also performs the serial-specific
 * initialization for the tty structure.
 */
int rs_open(struct tty_struct *tty, struct file *filp)
{
	struct t32_serial *info;
	int retval;

	info = &t32_info;
	if (serial_paranoia_check(info, tty->device, "rs_open"))
		return -ENODEV;
#ifdef SERIAL_DEBUG_OPEN
	printk("rs_open %s%d, count = %d\n", tty->driver.name, info->line,
		   info->count);
#endif
	info->count++;
	tty->driver_data = info;
	info->tty = tty;

	/*
	 * Start up serial port
	 */
	
	retval = startup(info);
	if (retval)
		return retval;

	retval = block_til_ready(tty, filp, info);
	if (retval) {
#ifdef SERIAL_DEBUG_OPEN
		printk("rs_open returning after block_til_ready with %d\n",
			   retval);
#endif
		return retval;
	}

	if ((info->count == 1) && (info->flags & S_SPLIT_TERMIOS)) {
		if (tty->driver.subtype == SERIAL_TYPE_NORMAL)
			*tty->termios = info->normal_termios;
		else
			*tty->termios = info->callout_termios;
	}

	info->session = current->session;
	info->pgrp = current->pgrp;

    rx_start(info);
    
#ifdef SERIAL_DEBUG_OPEN
	printk("rs_open ttyS%d successful...\n", info->line);
#endif
	return 0;
}


static void show_serial_version(void)
{
	printk("TRACE32 Teminal Emulation driver version 1.00\n");
}


/* rs_init inits the driver */
static int  __init rs_t32_init(void)
{
	int flags;
	struct t32_serial *info;

	/* Setup base handler, and timer table. */
	init_bh(SERIAL_BH, do_serial_bh);

	show_serial_version();

	/* Initialize the tty_driver structure */

	// set the tty_struct pointers to NULL to let the layer
	// above allocate the structs.
	serial_table[0] = NULL;
		
	memset(&serial_driver, 0, sizeof(struct tty_driver));

	serial_driver.magic = TTY_DRIVER_MAGIC;
	serial_driver.name = "ttyS";
	serial_driver.major = TTY_MAJOR;
	serial_driver.minor_start = 64;
#ifdef CONFIG_CONSOLE_ON_SC28L91	
	serial_driver.minor_start += 1;
#endif
	serial_driver.num = 1;
	serial_driver.type = TTY_DRIVER_TYPE_SERIAL;
	serial_driver.subtype = SERIAL_TYPE_NORMAL;
	serial_driver.init_termios = tty_std_termios;

	serial_driver.init_termios.c_cflag =
		B9600 | CS8 | CREAD | HUPCL | CLOCAL;
	serial_driver.flags = TTY_DRIVER_REAL_RAW;
	serial_driver.refcount = &serial_refcount;
	serial_driver.table = serial_table;
	serial_driver.termios = serial_termios;
	serial_driver.termios_locked = serial_termios_locked;

	serial_driver.open = rs_open;
	serial_driver.close = rs_close;
	serial_driver.write = rs_write;
	serial_driver.flush_chars = rs_flush_chars;
	serial_driver.write_room = rs_write_room;
	serial_driver.chars_in_buffer = rs_chars_in_buffer;
	serial_driver.flush_buffer = rs_flush_buffer;
	serial_driver.ioctl = rs_ioctl;
	serial_driver.throttle = rs_throttle;
	serial_driver.unthrottle = rs_unthrottle;
	serial_driver.set_termios = rs_set_termios;
	serial_driver.stop = rs_stop;
	serial_driver.start = rs_start;
	serial_driver.hangup = rs_hangup;
	serial_driver.set_ldisc = rs_set_ldisc;

	/*
	 * The callout device is just like normal device except for
	 * major number and the subtype code.
	 */
	callout_driver = serial_driver;
	callout_driver.name = "t32";    // "cua"
	callout_driver.major = TTYAUX_MAJOR;
	callout_driver.subtype = SERIAL_TYPE_CALLOUT;

	if (tty_register_driver(&serial_driver))
		panic("Couldn't register serial driver\n");
	if (tty_register_driver(&callout_driver))
		panic("Couldn't register callout driver\n");

	save_flags(flags);
	cli();
    
    info = &t32_info;
    
    info->incount  = &T32INBUF[0];
    info->outcount = &T32OUTBUF[0];
    info->inbuf    = T32INBUF+4;
    info->outbuf   = T32OUTBUF+4;
    
		info = &t32_info;
		info->magic = SERIAL_MAGIC;
		info->tty = 0;
        info->line = 0;
#ifdef CONFIG_CONSOLE_ON_ATMEL
		info->is_cons = 1;
#else
		info->is_cons = 0;
#endif	
#ifdef CONFIG_CONSOLE_ON_SC28L91
		info->line += 1;
#endif
		info->close_delay = 50;
		info->closing_wait = 3000;
		info->event = 0;
		info->count = 0;
		info->blocked_open = 0;
		info->tqueue.routine = do_softint;
		info->tqueue.data = info;
		info->tqueue_hangup.routine = do_serial_hangup;
		info->tqueue_hangup.data = info;
		info->callout_termios = callout_driver.init_termios;
		info->normal_termios = serial_driver.init_termios;
		init_waitqueue_head(&info->open_wait);
		init_waitqueue_head(&info->close_wait);
		info->rx_buf = rx_buf1;

		printk("%s%d", serial_driver.name, info->line);
		printk(" is a TRACE32 Terminal Emulation\n");
	
	restore_flags(flags);
	// hack to do polling
	serialpoll.routine = serpoll;
	serialpoll.data = 0;

	return 0;
}

module_init(rs_t32_init);

#if 0

static void dbg_putc (int ch)
{
}

static void dbg_print(const char *str)
{
	const char *p;

	for (p = str; *p; p++) {
		if (*p == '\n') {
			dbg_putc('\r');
		}
		dbg_putc(*p);
	}
}

static void dbg_printk(const char *fmt, ...)
{
	char tmp[256];
	va_list args;

	va_start(args, fmt);
	vsprintf(tmp, fmt, args);
	va_end(args);
	dbg_print(tmp);
}

static void rs_t32_print(const char *str)
{
	dbg_printk(str);
}

static void dump_a(unsigned long a, unsigned int s)
{
	unsigned long q;

	for (q = 0; q < s; q++) {
		if (q % 16 == 0) {
			dbg_printk("%08X: ", q + a);
		}
		if (q % 16 == 7) {
			dbg_printk("%02X-", *(unsigned char *) (q + a));
		} else {
			dbg_printk("%02X ", *(unsigned char *) (q + a));
		}
		if (q % 16 == 15) {
			dbg_printk(" :\n");
		}
	}
	if (q % 16) {
		dbg_printk(" :\n");
	}
}
#endif

static kdev_t t32_console_device(struct console *c)
{

	return MKDEV(TTY_MAJOR, 64 + c->index);
}

int t32_console_setup(void)
{
  return 0;
}

void t32_console_write (struct console *co, const char *str,
			   unsigned int count)
{
	struct t32_serial *info;

	info = &t32_info;

	if (!t32_console_initialized) {
		init_console(info);
		tx_stop(info);
		rx_stop(info);
		tx_start(info);
		rx_start(info);
	}

    	while (count--) {
        	if (*str == '\n')
           		rs_put_char(info,'\r');
        	rs_put_char(info, *str++ );
    	}
}

static struct console t32_driver = {
	name:		"ttyS",
	write:		t32_console_write,
	read:		NULL,
	device:		t32_console_device,
	wait_key:	NULL,
	unblank:	NULL,
	setup:		t32_console_setup,
	flags:		CON_PRINTBUFFER,
	index:		-1,
	cflag:		0,
	next:		NULL
};

void t32_console_init(void)
{
	register_console(&t32_driver);
}
