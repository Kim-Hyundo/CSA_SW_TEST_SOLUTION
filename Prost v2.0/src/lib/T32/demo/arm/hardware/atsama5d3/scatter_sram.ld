LR_IROM1 0x00300000 0x1000  {    ; load code region size_region
  ER_IROM1 0x00300000 0x1000{  ; load address = execution address
   startup_sram.o (INIT, +First)
   * (+RO)
  }
}
LR_IRAM1 0x00302000 0x000000600  {   ; stack region
  
  RW_IRAM1 0x00302000 0x00000400  {  ; stack
   startup_sram.o (+RW +ZI)
  }
  RW_IRAM2 0x00302400 0x00000200  {
   * (+RW +ZI)
  }
}
