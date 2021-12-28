MEMORY 
{
	SRAM : ORIGIN = 1K, LENGTH = 191K
}

ENTRY(_start)

SECTIONS
{
	.text : {
		crt0* (.text)
		* (.init)
		* (.text)
		* (.text.*)
		* (.glue_7)
		* (.glue_7t)
		_fini = .;
		* (.fini)
	} > SRAM

	.rodata : {
		* (.rodata)
		* (.rodata.*)
		* (.ARM.extab* .gnu.linkonce.armextab.*) 
	} > SRAM

	PROVIDE(__exidx_start = .);
	.ARM.exidx : { 
		*(.ARM.exidx* .gnu.linkonce.armexidx.*) 
	} > SRAM
	PROVIDE(__exidx_end = .);

	.data : {
		__init_array_start = .;
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array))
		__init_array_end = .;
		* (.fini_array)
		* (.jcr)
		* (.data.*)
		* (.data)
		* (.sdata)
	} > SRAM

	__bss_start = .;
	.bss : {
		* (.sbss)
		* (.bss)
		* (.bss.*)
	} > SRAM
	__bss_end = .;

	__heap_start = .;

	.ARM.attributes 0 : { KEEP (*(.ARM.attributes)) KEEP (*(.gnu.attributes)) }
}

__stack_end = ORIGIN(SRAM)+LENGTH(SRAM);
__data_vaddr = ADDR(.data);
__data_laddr = LOADADDR(.data);
__data_size  = SIZEOF(.data);

