On early Silicon Revisions before a B0 ROM a valid boot image must be on the SD-Card/<bootsource> otherwise JTAG stays disabled.

= Example Bootimage =
  # Endless Loop in AARCH64/AARCH32 ARM+THUMB
  echo "0xea000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 > ./bootloop.bin
  echo "0x14000000" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./bootloop.bin
  echo "0xe0011001" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./bootloop.bin
  echo "0xeafffffe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./bootloop.bin
  echo "0xe7fee7fe" | sed -E 's#0x(..)(..)(..)(..)#0x\4\3\2\1#g' | xxd -r -g0 >> ./bootloop.bin

  ./mkimage_imx8 -loader ./bootloop.bin 0x7e1000 -out ./sdcard-a53.mkimage

  dd if=/dev/zero of=./bootimage-imx8mq-evk-rev-a0-bootloop-a53.img bs=$((0x8400)) count=1
  cat sdcard-a53.mkimage >> ./bootimage-imx8mq-evk-rev-a0-bootloop-a53.img
stops the A53 bootcore on a endless loop in the BootROM.

= Alternative use files in demo folder =
In either case, the provided bootimage created with the above steps may be used.
  gzip -d bootimage-imx8mq-evk-rev-a0-bootloop-a53.img.gz

Copy this image to the SD-Card:
  dd if=bootimage-imx8mq-evk-rev-a0-bootloop-a53.img of=/dev/<sd-card-dev> conv=notrunc bs=1k
  # alternative use e.g. etcher.io