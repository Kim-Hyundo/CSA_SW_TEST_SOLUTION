; --------------------------------------------------------------------------------
; @Title: Readme - Handle problems caused by SoC Cpu-Idle in Linux
; @Description:
;   In some Linux systems the Cpu-Idle implementations disable the debug logic
;   and/or prevent access to the cores. Typical scenarios are
;     * DEBUGPORTFAIL when attaching or while the session
;     * 'running (no power)' state in the command line
;     * inconsistent runstates of the cores
;   . As the offchip-debugger requires access to the cpu-core the idle-states must 
;   be disabled in order to debug. This document sums up different variants how to 
;   disable the Linux 'cpuidle' framework.
;   Please check also the implementation of the platform BSP.
; @Author: AME
; @Copyright: (C) 1989-2020 Lauterbach GmbH, licensed for use with TRACE32(R) only
; --------------------------------------------------------------------------------
; $Id: readme-idlestates.txt 15873 2020-03-24 13:23:11Z amerkle $

= Variant 1 - Linux Commandshell =
Usecase: Kernel/Module/Userspace/ATF runtime debugging (Attach debugging)
Prerequisites:
  * Linux is booted up
  * access to Linux commandshell
  * Kernel uses Cpu-Idle framework
Advantage:
  * no change in low-level boot process
  * suitable for any product livecycle
Disadvantage:
  * not suitable for crash analysis

$ cat << EOF > disable-idlestates.sh
#!/bin/sh
# Query SYSFS and disable all registered cpuidle states
idlestates=$(ls /sys/devices/system/cpu/cpu**/cpuidle/state**/disable 2> /dev/null)
for state in ${idlestates}; do
  echo "echo 1 > ${state}"
  echo 1 > ${state}
done
EOF
$ chmod +x disable-idlestates.sh
$ ./disable-idlestates.sh

= Variant 2 - DTB =
Usecase: Kernel/Module/Userspace/ATF runtime debugging (Attach debugging)
Usecase: Kernel/Driver boot debugging (Start/Up debugging)
Prerequisites:
  * Access to DTB/DTS file
  * BSP maintains IDLE-STATES via DTB
Advantage:
  * suitable development/testing livecycle
  * automatization
Disadvantage:
  * boot process needs to be modified
  * not available on all BSPs

dtc -O dts -o <chip>-<board>-<config>-noidle.dts -I dtb <chip>-<board>-<config>.dtb
cat << EOF >> <chip>-<board>-<config>-noidle.dts
/ {
cpus {
/delete-node/ idle-states;
};
};
EOF
dtc -O dtb -o <chip>-<board>-<config>-noidle.dtb -I dts <chip>-<board>-<config>-noidle.dts
Now flash the new DTB "<chip>-<board>-<config>-noidle.dtb" onto the board.

= Variant 2a - DTB with FIT/ITB =
When using a Flattened-Image-Tree/Image-Tree-Blob you may put multiple DTBs into the blob.

cat << EOF > kernel_fdt_simpleramdisk.its
/dts-v1/;
/ {
	description = "Simple image with single Linux kernel and FDT blob";
	#address-cells = <1>;

	images {
		kernel@1 {
			(...)
		};
		fdt@1 {
			description = "Flattened Device Tree blob - noidle";
			data = /incbin/("<path to>/<chip>-<board>-<config>-noidle.dtb");
			type = "flat_dt";
			arch = "<arch>";
			compression = "none";
			load = <addr>;
		};
		fdt@2 {
			description = "Flattened Device Tree blob - idle";
			data = /incbin/("<path to>/<chip>-<board>-<config>.dtb");
			type = "flat_dt";
			arch = "<arch>";
			compression = "none";
			load = <addr>;
		};
		ramdisk@1 {
			(...)
		};
	};

	configurations {
		default = "conf@1";
		conf@1 {
			description = "Linux DTB Ramdisk - noidle";
			kernel = "kernel@1";
			fdt = "fdt@1";
			ramdisk = "ramdisk@1";
		};
		conf@2 {
			description = "Linux DTB Ramdisk - idle";
			kernel = "kernel@1";
			fdt = "fdt@2";
			ramdisk = "ramdisk@1";
		};
	};
};
EOF
Boot Linux without IDLE
  U-Boot> bootm <addr>#conf@1
Boot Linux with IDLE
  U-Boot> bootm <addr>#conf@2

= Variant 3 - Bootargs =
Usecase: Kernel/Module/Userspace/ATF runtime debugging (Attach debugging)
Usecase: Kernel/Driver boot debugging (Start/Up debugging)
Prerequisites:
  * Access to bootloader commandshell/Boot environment
  * Kernel supports 'cpuidle.off' Module Parameter <kernelsrc>/drivers/cpuidle/cpuidle.c
  * Kernel uses 'cpuidle' Framework
Advantage:
  * suitable development/testing livecycle
  * automatization
Disadvantage:
  * boot process needs to be modified
  * not available on all BSPs

Add the parameter:
  cpuidle.off=1
to the bootargs string. E.g.
  U-Boot> setenv bootargs ${bootargs} cpuidle.off=1
  U-Boot> boot<m/i> (...)

= Variant 3a - Bootargs =
Usecase: Kernel/Module/Userspace/ATF runtime debugging (Attach debugging)
Usecase: Kernel/Driver boot debugging (Start/Up debugging)
Prerequisites:
  * Access to bootloader commandshell/Boot environment
  * Kernel supports 'nohlt' parameter
  * Kernel CONFIG Parameter: CONFIG_GENERIC_IDLE_POLL_SETUP
Advantage:
  * suitable development/testing livecycle
  * automatization
Disadvantage:
  * boot process needs to be modified
  * not available on all BSPs
  * sisables IDLE handling completely and uses busy polling instead
    CPU will not call WFI/WFE anymore
    => Power Dissipation
    => Onchip/Offchip trace will be filled up by Idle-Polling

Add the parameter:
  nohlt
to the bootargs string. E.g.
  U-Boot> setenv bootargs ${bootargs} nohlt
  U-Boot> boot<m/i> (...)

= Variant 4 - Recompile =
Prerequisites:
  * Kernel uses Cpu-Idle framework

Recompile the kernel without Cpu-Idle support. Disable
  CONFIG_CPU_IDLE
in Kernel config.

