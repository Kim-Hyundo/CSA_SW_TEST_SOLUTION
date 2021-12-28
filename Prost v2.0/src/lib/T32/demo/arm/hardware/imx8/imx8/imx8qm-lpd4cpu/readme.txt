In order to start the A53/A72/M4_0/M4_1 a valid boot image is required.
= Example Bootimage A53/A72 (requires files from the NXP BSP) =
  #create endless loop
  echo "0xea000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 > loop.bin
  echo "0x14000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> loop.bin
  echo "0xeafffffe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> loop.bin
  # boot image for A53
  mkimage_imx8 -dcd <dcd-file> -scfw <sc_fw-file> -ap ./loop.bin a53 0x80000000 -dev sd -out ./sdcard-dcd.mkimage
  dd if=/dev/zero of=./bootimage-mx8qmlpd4cpu-bootloop-a53.img bs=$((0x8400)) count=1
  cat ./sdcard-dcd.mkimage >> bootimage-mx8qmlpd4cpu-bootloop-a53.img
  # boot image for A72
  mkimage_imx8 -dcd <dcd-file> -scfw <sc_fw-file> -ap ./loop.bin a72 0x80000000 -dev sd -out ./sdcard-dcd.mkimage
  dd if=/dev/zero of=./bootimage-mx8qmlpd4cpu-bootloop-a72.img bs=$((0x8400)) count=1
  cat ./sdcard-dcd.mkimage >> bootimage-mx8qmlpd4cpu-bootloop-a72.img
  
= Example Bootimage M4_0 (requires files from the NXP BSP) =
  #create endless loop
  echo "0x20001000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 > ./m4.bin
  echo "0x00000009" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./m4.bin
  echo "0xe7fee7fe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./m4.bin
  # boot image for M4
  mkimage_imx8 -dcd <dcd-file> -scfw <sc_fw-file> -m4 ./m4.bin 0 0x34fe0000 -dev sd -out ./sdcard-dcd.mkimage
  dd if=/dev/zero of=./bootimage-mx8qmlpd4cpu-bootloop-m4_0.img bs=$((0x8400)) count=1
  cat ./sdcard-dcd.mkimage >> bootimage-mx8qmlpd4cpu-bootloop-m4_0.img

= Alternative use files in demo folder =
  # A53
  gzip -d bootimage-mx8qmlpd4cpu-bootloop-a53.img.gz
  # A72
  gzip -d bootimage-mx8qmlpd4cpu-bootloop-a72.img.gz
  # M4_0
  gzip -d bootimage-mx8qmlpd4cpu-bootloop-m4_0.img.gz
  # M4_1
  gzip -d bootimage-mx8qmlpd4cpu-bootloop-m4_1.img.gz

Copy this image to the SD-Card:
  # A53
  dd if=/dev/zero of=/dev/<sd-card-dev> conv=notrunc bs=1k count=4096
  dd if=bootimage-mx8qmlpd4cpu-bootloop-a53.bin of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # A72
  dd if=/dev/zero of=/dev/<sd-card-dev> conv=notrunc bs=1k count=4096
  dd if=bootimage-mx8qmlpd4cpu-bootloop-a72.bin of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # M4_0
  dd if=/dev/zero of=/dev/<sd-card-dev> conv=notrunc bs=1k count=4096
  dd if=bootimage-mx8qmlpd4cpu-bootloop-m4_0.bin of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # M4_1
  dd if=/dev/zero of=/dev/<sd-card-dev> conv=notrunc bs=1k count=4096
  dd if=bootimage-mx8qmlpd4cpu-bootloop-m4_1.bin of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # alternative use e.g. etcher.io

= Board settings =
Put the SD-Card into the board.
Select BOOT-SW500[6..1]=0y001100