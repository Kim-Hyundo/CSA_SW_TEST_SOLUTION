
RM := rm -rf
 
OBJS += \
./arm-dcc.o \
./main.o \
 

DEPS += \
${addprefix ./, \
arm-dcc.d \
main.d \
}

%.o: %.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	@echo $(CROSS_COMPILE)gcc -O0 -Wall -c -o$@ $<
	@$(CROSS_COMPILE)gcc -O0 -Wall -c -o$@ $< && \
	echo -n $(@:%.o=%.d) $(dir $@) > $(@:%.o=%.d) && \
	$(CROSS_COMPILE)gcc -MM -MG -P -w -O0 -Wall -c  $< >> $(@:%.o=%.d)
	@echo 'Finished building: $<'
	@echo ' '
	
LIBS := -lpthread

all: perf_linux_dcc

perf_linux_dcc: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	@echo $(CROSS_COMPILE)gcc -g -o perf_linux_dcc $(OBJS) $(LIBS)
	@$(CROSS_COMPILE)gcc -g -o perf_linux_dcc $(OBJS) $(LIBS)
	@$(CROSS_COMPILE)strip -g perf_linux_dcc
	@rm -f *.o *.d
	@echo 'Finished building target: $@'
	@echo ' '
	
perf_linux_dcc.static: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	@echo $(CROSS_COMPILE)gcc -static -o perf_linux_dcc.static $(OBJS) $(LIBS)
	@$(CROSS_COMPILE)gcc -static -o perf_linux_dcc.static $(OBJS) $(LIBS)
	@$(CROSS_COMPILE)strip perf_linux_dcc.static
	@rm -f *.o *.d
	@echo 'Finished building target: $@'
	@echo ' '
	
	
clean:
	-$(RM) $(OBJS)$(DEPS) perf_linux_dcc*
	-@echo ' '
