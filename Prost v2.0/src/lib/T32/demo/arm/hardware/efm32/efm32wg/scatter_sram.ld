LR_IROM1 0x20000000 0x1000  {    ; load code region size_region
  ER_IROM1 0x20000000 0xFFF{  ; load address = execution address
   startup_sram.o (INIT, +First)
   * (+RO)
  }
}
LR_IRAM1 0x20001000 0x000008000  {
  
  RW_IRAM1 0x20001000 0x00000400  {  ; stack
   startup_sram.o (+RW +ZI)
  }
  RW_IRAM2 0x20001400 0x00006BFF  {
   * (+RW +ZI)
  }
}
