# MakeFile to compile via a Visual Studio 2010 environment
# Open a "Visual Studio Command Prompt" and compile with
#
#    nmake -f make.vs
#

COPTS = /c /W3 /Z7 /O2

DLL1 = {tpiu_print.dll

OBJECTS1 = {pipecsproto} {tpiu_print}

# Enclosing the object names in {} means we can now replace
# "{" with "vs32\" (or "vs64") and "}" with ".obj"

!if "$(PLATFORM)" != "X64" && "$(PLATFORM)" != "x64"
!message PLATFORM = "$(PLATFORM)" : 32 Bit Build
DLL1     = $(DLL1:{=vs32\)
OBJECTS1 = $(OBJECTS1:{=vs32\)

# create build directory if it does not exist
!if [if not exist vs32 mkdir vs32]
!endif

!else
!message PLATFORM = "$(PLATFORM)" : 64 Bit Build

DLL1     = $(DLL1:{=vs64\)
OBJECTS1 = $(OBJECTS1:{=vs64\)

# create build directory if it does not exist
!if [if not exist vs64 mkdir vs64]
!endif

!endif

OBJECTS1 = $(OBJECTS1:}=.obj)

all: $(DLL1)

$(DLL1): $(OBJECTS1)
	link -dll -out:$@ $**

{src}.c{vs32}.obj:
	cl $(COPTS) /Fo$@ $<

{src}.c{vs64}.obj:
	cl $(COPTS) /Fo$@ $<

clean:
	rmdir /S /Q vs32 vs64

cleanmost:
	del /Q vs32\*.obj vs32\*.lib vs32\*.exp vs64\*.obj vs64\*.lib vs64\*.exp
