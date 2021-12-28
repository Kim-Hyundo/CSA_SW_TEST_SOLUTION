
ppwd=$(dirname "$0")
MACHINE='pc_linux'
MACHINE_TYPE=`uname -m`
if [ $MACHINE_TYPE == 'x86_64' ]; then
  MACHINE='pc_linux64'
fi

cd $ppwd
#execute the first instance of TRACE32 running the Cortex-M4F
$T32SYS/bin/$MACHINE/t32marm-qt -c $ppwd/config_amp.t32 $T32SYS 10000 LPC4330 CORE=1 -s $ppwd/lpc4330_multisieve_amp_demo.cmm
