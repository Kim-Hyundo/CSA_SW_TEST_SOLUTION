LR_IROM1 0x00000000 0x440  {    ; load region size_region
  ER_IROM1 0x00000000 0x8{  ; load address = execution address
   startup_flash.o (RESET, +First)
  }
  ER_EMPTY 0x8 EMPTY 0x438
  {
  }
}
LR_IROM2 0x00000440 0x3FBC0 {    ; load region size_region
  ER_IROM2 0x00000440 0x3FBBF{  ; load address = execution address
   * (+RO)
  }
}
LR_IRAM1 0x20000000 0x2000  { 

  RW_IRAM1 0x20000000 EMPTY 0x00002000  {  ; Empty for flash driver
  }
}
LR_IRAM2 0x20002000 0x6000  { 
  RW_IRAM2 0x20007C00 0x00000400   {  ; stack
   startup_flash.o (+RW +ZI)
  }
  RW_IRAM3 0x20002000 0x00005BFF {
   * (+RW +ZI)
  }
}
