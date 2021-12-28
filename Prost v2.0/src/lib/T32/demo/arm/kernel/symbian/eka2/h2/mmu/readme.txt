
Usage of Debugger MMU for Symbain OS EKA2

Debugging Symbian OS can be done in two modes:
With or without the debugger MMU enabled.

Unlike other operating systems, Symbian OS EKA2 uses different
virtual code addresses for each process. This allows the debugger
to run completely in virtual address mode, without the need
for the debugger to know the virtual to physical address 
translation of the target. All debugger MMU translations are
switched off in this case (sYstem.Option MMU OFF, MMU.OFF).

In this case you can see the code and set breakpoints of any
process at any time you want.

However, the data section of the processes are located on
the same virtual address, but on different physical addresses.
On a process switch, the MMU is reprogrammed so that the current
running process has access to it's data segment on the virtual
address. 

Without the debugger knowing any address translation (i.e.
working only on virtual addresses), it has only access to
the current data segment, which is mapped in to the MMU.
That is, you can see the code of all processes, but you
can only see the data of the current running process. 
Inspecting variables of other processes is not possible.

This mode, having the debugger MMU disabled, is much
easier to handle, but enabling the debugger MMU gives you
access to all data areas of all processes.

With the debugger MMU enabled (SYStem.Option MMU ON, MMU.ON),
each loaded process get's a space id (equals process id), that
specifies it's MMU translation table. By extending the virtual
address with this space id, the debugger is now able to address
the virtual data of any process. You have full access to variables
of every process at any time.

In order for this to work, the symbols of the processes must
be located to the right space ids. I.e. each time, the process
id changes, the symbols must be reloaded.

The Symbian OS Awareness Manual gives more detailed information 
about the debugger MMU handling.

The script files in this directory enable the debugger MMU.
