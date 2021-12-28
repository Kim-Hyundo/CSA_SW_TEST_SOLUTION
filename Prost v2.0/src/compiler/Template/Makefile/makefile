################################################################################
# Automatically-generated file. Do not edit!
################################################################################

### $$${PROJECT_NAME}$$$
###

### $$${COMPILER_PATH}$$$
###

### $$${workspace_loc}$$$
###

### $$${INCLUDE_PATH}$$$
###
INC += -I"$(COMPILER)\ctc\include"
INC += -I"$(COMPILER)\ctc\include.lsl" 

### $$${LIBRARY_PATH}$$$
###


### $$${TARGET_INFO}$$$
###


### $$${COMPILER_OPTION}$$$
###

### $$${LINKER_OPTION}$$$
###

all :
-include "subdir.mk"
### $$${SUBDIRMK_INCLUDE_PATH}$$$
###


all : "$(PROJ).elf"

"$(PROJ).elf" : $(OBJ_FILES)  ".$(PROJ).elf.opt"
	@echo Linking to ${@F}
	@$(COMPILER)\ctc\bin\cctc -f ".$(PROJ).elf.opt"

".$(PROJ).elf.opt" : .refresh
	@argfile ".$(PROJ).elf.opt" -o "$(PROJ).elf" $(OBJ_FILES) $(COMPILE_OPT) $(LINK_OPT) $(LIBS)
DEPENDENCY_FILES += ".$(PROJ).elf.d"
-include $(DEPENDENCY_FILES)



#GENERATED_FILES += "$(PROJ).elf" "$(PROJ)*.sre" "$(PROJ)*.hex" "$(PROJ).map*" "$(PROJ).mdf" ".$(PROJ).elf.opt" ".$(PROJ).elf.d"

clean : ".clean.opt"
	@echo Cleaning
	@rm -f -m ".clean.opt"

".clean.opt" : .refresh
	@argfile ".clean.opt" $(GENERATED_FILES)

#GENERATED_FILES += ".clean.opt"

.PHONY : .dummy .refresh
