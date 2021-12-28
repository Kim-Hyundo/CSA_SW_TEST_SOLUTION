LR_IROM1 0x80002000 0x1000  {    ; load code region size_region
  ER_IROM1 0x80002000 0x1000{  ; load address = execution address
   startup_sdram.o (INIT, +First)
   * (+RO)
  }
}
LR_IRAM1 0x80005000 0x000001000  {   ; stack region
  
  RW_IRAM1 0x80005000 0x00000400  {  ; stack
   startup_sdram.o (+RW +ZI)
  }
  RW_IRAM2 0x80005400 0x00000C00  {
   * (+RW +ZI)
  }
}
