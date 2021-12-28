In order to start the A35/M4 a valid boot image is required.
The script set is ready to run on i.MX8QXP RevC Si B0 board.
= Example Bootimage M4+A35 Si B0 (requires files from the NXP BSP) =
  #create endless loop
  echo "0xea000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 > loop.bin
  echo "0x14000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> loop.bin
  echo "0xeafffffe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> loop.bin
  echo "0x20001000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 > m4.bin
  echo "0x00000009" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> m4.bin
  echo "0xe7fee7fe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> m4.bin
  # boot image for M4+A35
  mkimage_imx8 -soc QX -rev B0 -append <ahab-container-file> -dev sd -c -scfw <sc_fw-file> -m4 ./m4.bin 0 0x34fe0000 -ap ./loop.bin a35 0x80000000 -out ./sdcard-dcd.mkimage
  dd if=/dev/zero of=./bootimage-mx8qxp-mek-bootloop-a35-m4.img bs=$((0x8000)) count=1
  cat ./sdcard-dcd.mkimage >> bootimage-mx8qxp-mek-bootloop-a35-m4.img
  
= Example Bootimage SECO + SCU only (requires files from the NXP BSP) =
  This image starts nothing except the SCU & SECO cores.
  -> The CSGPR can be used to start the cores.
  # boot image
  mkimage_imx8 -soc QX -rev B0 -append <ahab-container-file> -c -scfw <sc_fw-file> -out flash.mkimage
  dd if=/dev/zero of=./bootimage-mx8qxp-mek-csgpr.img bs=$((0x8000)) count=1
  cat ./sdcard-dcd.mkimage >> ./bootimage-mx8qxp-mek-csgpr.img
  
= Alternative use files in demo folder =
  # M4+A35 on IMX8QXP-CPU RevC Si B0
  gzip -d bootimage-mx8qxp-mek-bootloop-a35-m4.img.gz
  # CSGPR
  gzip -d bootimage-mx8qxp-mek-csgpr.img.gz

Copy this image to the SD-Card:
  # M4+A35 for RevC Board
  dd if=bootimage-mx8qxp-mek-bootloop-a35-m4.img of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # CSGPR
  dd if=bootimage-mx8qxp-mek-csgpr.img of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # alternative use e.g. etcher.io
  
= Board settings =
Put the SD-Card into the board.
Select BOOT-SW2[4..1]=0y0011

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