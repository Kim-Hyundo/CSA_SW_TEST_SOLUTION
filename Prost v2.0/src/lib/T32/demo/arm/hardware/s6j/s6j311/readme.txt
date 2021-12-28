To connect to an S6J311 device the nSRST line must not be used. Therefore
e.g. the SK-Leo evaluation board must be modified as shown in skleo-modification1&2.
The modification consist of 
 (1) disconnecting the nSRST line from the chip
 (2) wiring a pullup resistor ~10k between nRST of the chip & VCC
 (3) connecting nSRST net of ARM20 & Mictor38 connector with RSTX
 
= TRACE on SKLEO =
By default only a 4bit Trace without TRACECTL is available on SK-LEO. 
The trace must therefore be configured in Continuous mode.

By setting Jumpers J107,J115,J120,J121 to MICTOR a full 8 Bit trace is available.
The bandwidth should then be enough to do a full data-trace.