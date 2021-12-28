# AMP Example makefile

# CPUNAME=
# BOARDNAME=
# BASENAME=
all:
	make -C master $@
	make -C slave1 $@
	make -C slave2 $@

target:
	make -C master $@
	make -C slave1 $@
	make -C slave2 $@

-include special-rule.mk.internal
