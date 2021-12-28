# AMP Example makefile

CPUNAME=ZYNQ-ULTRASCALE+
BOARDNAME=ZCU102
BASENAME=zcu102

all:
	make -C master $@
	make -C slave1 $@
	make -C slave2 $@

target:
	make -C master $@
	make -C slave1 $@
	make -C slave2 $@

-include special-rule.mk.internal
