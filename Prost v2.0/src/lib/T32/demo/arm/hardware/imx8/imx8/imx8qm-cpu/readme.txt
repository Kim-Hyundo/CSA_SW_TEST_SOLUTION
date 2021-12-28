In order to start the A53/A72/M4_0/M4_1 a valid boot image is required.
The script set is ready to run on i.MX8QM MEK RevC Si B0 board.
= Example Bootimage A53 + M4 (requires files from the NXP BSP) =
  #create endless loop
  echo "0xea000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 > ./a53.bin
  echo "0x14000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./a53.bin
  echo "0xeafffffe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./a53.bin
  echo "0x20001000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 > ./m4.bin
  echo "0x00000009" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./m4.bin
  echo "0xe7fee7fe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./m4.bin
  # boot image for M4+A53
  mkimage_imx8 -soc QM -rev B0 -append <ahab-container-file> -c -scfw <sc_fw-file> -m4 ./m4.bin 0 0x34fe0000 -m4 ./m4.bin 1 0x38fe0000 -ap ./a53.bin a53 0x80000000 -out flash.mkimage
  dd if=/dev/zero of=./bootimage-mx8qm-mek-bootloop-a53-m4.img bs=$((0x8000)) count=1
  cat ./sdcard-dcd.mkimage >> ./bootimage-mx8qm-mek-bootloop-a53-m4.img

= Example Bootimage SECO + SCU only (requires files from the NXP BSP) =
  This image starts nothing except the SCU & SECO cores.
  -> The CSGPR can be used to start the cores.
  # boot image
  mkimage_imx8 -soc QM -rev B0 -append <ahab-container-file> -c -scfw <sc_fw-file> -out flash.mkimage
  dd if=/dev/zero of=./bootimage-mx8qm-mek-csgpr.img bs=$((0x8000)) count=1
  cat ./sdcard-dcd.mkimage >> ./bootimage-mx8qm-mek-csgpr.img

= Alternative use files in demo folder =
  # A53 + M4_0 + M4_1 bootloop
  gzip -d bootimage-mx8qm-mek-bootloop-a53-m4.img.gz
  # CSGPR
  gzip -d bootimage-mx8qm-mek-csgpr.img.gz

Copy this image to the SD-Card:
  dd if=/dev/zero of=/dev/<sd-card-dev> conv=notrunc bs=1k count=4096
  # either
  dd if=bootimage-mx8qm-mek-bootloop-a53-m4.img of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # or
  dd if=bootimage-mx8qm-mek-csgpr.img of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # alternative use e.g. etcher.io

= Board settings =
Put the SD-Card into the board.
Select BOOT-SW2[6..1]=0y001100

= ECC in CM4-TCM =
It's recommended to disable the ECC Multi-bit IRQ while the debugsession
(List&Dump windows open). The CM4 TCM is ECC protected. Every ECC fail will be
reported to the SCU which might trigger a full SoC reset in worst case.
Within TRACE32 we recommend to use
  Data.EPILOG
feature to disable the ECC when the core is halted.
You may consider re-activating the ECC protection on a core restart using
  Data.PROLOG
.

In order to use SYStem.Option DUALPORT ON we recommend to keep the RAM ECC
Multi-bit disabled.

Sequence:
; <recommended>
  Data.EPILOG.SEQuence SET EA:0xE0080480 %LE %Long 0x00300001
  Data.EPILOG.ON
; </recommended>
; <optional>
  Data.PROLOG.SEQuence SET EA:0xE0080480 %LE %Long 0x00300003
  Data.PROLOG.ON
; </optional>

Address: 0xE0080480
Name: LMEM Parity/ECC Control Register
Bit description:
 31:22 RESERVED
 21    Enable Cache Parity IRQ
 20    Enable Cache Parity Report
 19:17 RESERVED
 16    Enable RAM Parity Reporting
 15:10 RESERVED
 9     Enable RAM ECC 1-bit IRQ
 8     Enable RAM ECC 1-bit Report
 7:2   RESERVED
 1     Enable RAM ECC Multi-bit IRQ
 0     Enable RAM ECC Multi-bit