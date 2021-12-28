LR_IROM1 0x00000000 0x800  {    ; load region size_region
  ER_IROM1 0x00000000 0x8{  ; load address = execution address
   startup.o (RESET, +First)
  }
  FLASH 0x8 EMPTY 0x7F8
  {
  }
}
LR_IROM2 0x800 0x7800  { 
  ER_IROM2 0x00000800 0x7800{  ; load address = execution address
   * (+RO)
  }
  RW_IRAM1 0x1FFFFC00 0x00000400  {  ; stack
   startup.o (+RW +ZI)
  }
  RW_IRAM2 0x20000000 0x00000C00  {
   * (+RW +ZI)
  }
}
