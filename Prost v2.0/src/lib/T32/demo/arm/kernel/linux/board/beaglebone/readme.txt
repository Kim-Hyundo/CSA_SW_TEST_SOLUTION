Some Linux kernel versions disable the debug module for the AM335x. After the kernel boots, debugging is then not possible.
To avoid this, the kernel needs to be patched. The following argument has to be added to the am33xx_debugss_hwmod struct in
arch/arm/mach-omap2/omap_hwmod_33xx_data.c:

  .flags          = HWMOD_INIT_NO_IDLE,