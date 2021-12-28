
/*
 * Name: iRAM.ld 
 * 
 * Generated Linker Description File
 * Copyright (C) 2010 HighTec EDV-Systeme GmbH. 
 * (!Do not edit outsite of the protection areas!)
 *
 * Description: 
 * internal RAM configuration
 */

/*
 * Define Entrypoint of Executable
 */
ENTRY(_start)

/*
 * Global
 */

__USTACK_SIZE = DEFINED (__USTACK_SIZE) ? __USTACK_SIZE : 4K;  /* Section for ustack*/ 
__ISTACK_SIZE = DEFINED (__ISTACK_SIZE) ? __ISTACK_SIZE : 1K;  /* Section for istack*/ 
__HEAP_SIZE = DEFINED (__HEAP_SIZE) ? __HEAP_SIZE : 4K;  /* Section for heap*/ 
__CSA_SIZE = DEFINED (__CSA_SIZE) ? __CSA_SIZE : 16K;  /* Section for CSA*/ 


/*
 * internal RAM configuration
 */
MEMORY
{
	PMI_PSPR (wx!p):	org = 0x70100000, len = 64K  /*Scratch-Pad RAM (PSPR)*/ 
	DMI_DSPR (w!xp):	org = 0x70000000, len = 96K  /*Local Data RAM (DSPR)*/ 
	LMU_SRAM (wxp):	org = 0x90000000, len = 64K  /*Local Data RAM (LMU)*/ 
	
}			

SECTIONS
{
	/*Code-Sections*/
	
	/*
	 * Startup code for TriCore
	 */
	.startup_code  :
	{
		PROVIDE(__startup_code_start = .);
		
		*(.startup_code) /*Startup code for TriCore*/ 
		*(.startup_code*)
		
		PROVIDE(__startup_code_end = .);
		. = ALIGN(8);
		
	} > LMU_SRAM
	
	__PAGE = 0x70100000;
	__PAGE_STORAGE = .;
	OVERLAY __PAGE : 
	{
		.page1 {
			LONG(0x41)
			*/task1.o   (.text)
			*/task.o    (.text)
			*/funcasm.o (.text)
			*/sieve.o   (.text)
			* (.page1)
		}

		.page2 {
			LONG(0x42)
			*/blubber.o (.text)
			* (.page2)
		}
	
	} > PMI_PSPR AT > LMU_SRAM	
	
	/*
	 * Code section
	 */
	.text  :
	{
		PROVIDE(__text_start = .);
		
		*(.text) /*Code section*/ 
		*(.text*)
		*(.gnu.linkonce.t.*)
		
		PROVIDE(__text_end = .);
		. = ALIGN(8);
		
	} > LMU_SRAM
	
	/*
	 * Code executed before calling main
	 */
	.init  :
	{
		PROVIDE(__init_start = .);
		
		KEEP(*(.init)) /*Code executed before calling main*/ 
		KEEP(*(.init*))
		
		PROVIDE(__init_end = .);
		. = ALIGN(8);
		
	} > LMU_SRAM
	
	/*
	 * Code executed before exiting program
	 */
	.fini  :
	{
		PROVIDE(__fini_start = .);
		
		KEEP(*(.fini)) /*Code executed before exiting program*/ 
		KEEP(*(.fini*))
		
		PROVIDE(__fini_end = .);
		. = ALIGN(8);
		
	} > LMU_SRAM
	
	/*
	 * Section for trap table
	 */
	.traptab  :
	{
		PROVIDE(__traptab_start = .);
		
		*(.traptab) /*Section for trap table*/ 
		*(.traptab*)
		
		PROVIDE(__traptab_end = .);
		. = ALIGN(8);
		
	} > LMU_SRAM
	
	/*
	 * Section for interrupt table
	 */
	.inttab  :
	{
		PROVIDE(__inttab_start = .);
		
		*(.inttab) /*Section for interrupt table*/ 
		*(.inttab*)
		
		PROVIDE(__inttab_end = .);
		. = ALIGN(8);
		
	} > LMU_SRAM
	

	/*Normal Data-Sections*/
	
	/*
	 * Storage of write-protected data
	 */
	.rodata  :
	{
		PROVIDE(__rodata_start = .);
		
		*(.rodata) /*Storage of write-protected data*/ 
		*(.rodata*)
		*(.gnu.linkonce.r.*)
		*(.jcr*)
		*(.tm_clone_table*)
		
		PROVIDE(__rodata_end = .);
		. = ALIGN(8);
		
	} > LMU_SRAM 
	
	/*
	 * Initialised data
	 */
	.data  :
	{
		PROVIDE(__data_start = .);
		
		*(.data) /*Initialised data*/ 
		*(.data*)
		*(.gnu.linkonce.d.*)
		
		PROVIDE(__data_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR AT > LMU_SRAM 
	
	/*
	 * Not Initialised data
	 */
	.bss (NOLOAD) :
	{
		PROVIDE(__bss_start = .);
		
		*(.bss) /*Not Initialised data*/ 
		*(.bss*)
		*(.gnu.linkonce.b.*)
		
		PROVIDE(__bss_end = .);
		. = ALIGN(8);
		
	} > DMI_DSPR
	 
	/*
	 * Section for constructors
	 */
	.ctors          :
	{
		__CTOR_LIST__ = . ;

		LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2);
		KEEP (*crtbegin.o(.ctors))
		KEEP (*(EXCLUDE_FILE (*crtend.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
		LONG(0) ;
		__CTOR_END__ = . ;
		 . = ALIGN(8);
	}  > LMU_SRAM


	/*
	 * Section for destructors
	 */
	.dtors          :
	{
		__DTOR_LIST__ = . ;
		LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2);
		KEEP (*crtbegin.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
		LONG(0) ;
		__DTOR_END__ = . ;
		. = ALIGN(8);
	} > LMU_SRAM
	
	
	/*
	 * Section for clear table
	 */
	.clear_sec :
	{
		. = ALIGN(8);
		PROVIDE(__clear_table = .) ;
			LONG(0 + ADDR(.bss));	LONG(SIZEOF(.bss));
			LONG(-1);                 LONG(-1);
	} > LMU_SRAM
	 
	/*
	* Section for copy table
	*/	
	.copy_sec :
	{
		. = ALIGN(8);
		PROVIDE(__copy_table = .) ;
			LONG(LOADADDR(.data));	LONG(0 + ADDR(.data));	LONG(SIZEOF(.data));
			LONG(-1);                 LONG(-1);                  LONG(-1);
	} > LMU_SRAM 
	 
	
	/*
	 * Section for ustack
	 */	
	.ustack :
	{
		. = ALIGN(8);
		 __USTACK_BEGIN = . ;
		. += __USTACK_SIZE ;
		. = ALIGN(8);
		 __USTACK = . ;
		 __USTACK_END = . ;
	} > DMI_DSPR
	
	/*
	 * Section for istack
	 */	
	.istack :
	{
		. = ALIGN(8);
		 __ISTACK_BEGIN = . ;
		. += __ISTACK_SIZE ;
		. = ALIGN(8);
		 __ISTACK = . ;
		 __ISTACK_END = . ;
	} > DMI_DSPR
	
	/*
	 * Section for heap
	 */	
	.heap :
	{
		. = ALIGN(8);
		 __HEAP_BEGIN = . ;
		 __HEAP = . ;
		. += __HEAP_SIZE ;
		. = ALIGN(8);
		 __HEAP_END = . ;
	} > DMI_DSPR
	
	/*
	 * Section for CSA
	 */	
	.csa :
	{
		. = ALIGN(64);
		 __CSA_BEGIN = . ;
		 __CSA = . ;
		. += __CSA_SIZE ;
		. = ALIGN(64);
		 __CSA_END = . ;
	} > DMI_DSPR
	
}

