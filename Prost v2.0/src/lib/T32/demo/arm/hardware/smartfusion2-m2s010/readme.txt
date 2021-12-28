Microsemi Smartfusion2 SF2 Dev Kit
Ensure JP2 1-2 is shorted and a meaningful FPGA design is loaded.
On some boards the pullup/pulldown resistors R20/R25 connected to JP2 1-2 did not generate a proper logic level.
In such situations the 
SYStem.DETECT.DaisyChain
command showed in the AREA window a IR-Length of 8 (=FPGA TAP) only.
In case something like that shows up, please try to either
  REMOVE R20 (pullup)
OR
  Connect JP2 Pin 1 to GND