MEMORY 
{
	RAM : ORIGIN = 1K, LENGTH = 31K
}

ENTRY(_start)

SECTIONS
{
	.text : {
		* (.text)
		* (.glue_7)
		* (.glue_7t)
	} > RAM

	.rodata : {
		* (.rodata)
	} > RAM

	.data : {
		* (.data)
	} > RAM

	_bss_start = .;
	.bss : {
		* (.bss)
		* (.sbss)
	} > RAM
	_bss_end = .;

	_sp = 0x008000;
}

