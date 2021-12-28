= Power Management =
In order to properly use the debugger the suspend feature of the TEGRA K1 must be disabled.
To do so, please ensure the PMC section in the DTB does not allow any suspend modes:

Device TREE - dts file
    pmc {
        status = "okay";
        nvidia,invert-interrupt;
        nvidia,suspend-mode = <100>;             /* must be not 0,1,2 or remove line */
        nvidia,cpu-pwr-good-time = <500>;
        nvidia,cpu-pwr-off-time = <300>;
        nvidia,core-pwr-good-time = <3845 3845>;
        nvidia,core-pwr-off-time = <2000>;
        nvidia,lp0-vec = <0xf46ff000 2064>;
        nvidia,core-power-req-active-high;
        nvidia,sys-clock-req-active-high;
    };
    
    
= Clock initialization =
Note: Only interesting for customers that want to debug the EARLY BOOT phase of the kernel.
In
  tegra12x_early_init
the clock infrastructure is reconfigured. This cuts the connection for the debugger as the debug
clocks get disabled for a short period. It's possible to reconnect using
  SYStem.Mode.Attach 
immediately after the reconfiguration.