MEMORY 
{
    SRAM  : ORIGIN = 0x0, LENGTH = 0xffffffff
}

ENTRY(_start)

SECTIONS
{
    .text : {
        LONG(0x00000000)
        KEEP(* (.text.crt))
        KEEP(* (.text.crt0))
        * (.text*)
    } > SRAM

    .rodata : ALIGN(6) {
        * (.rodata*)
        * (.constdata*)
    } > SRAM

    .rel_dyn_start : {
        * (.__rel_dyn_start);
    } > SRAM
    .rel.dyn : {
        * (.rel*)
    } > SRAM
    .rel_dyn_end : {
        * (.__rel_dyn_end);
    } > SRAM

    .dynsym_start : {
        * (.__dynsym_start);
    } > SRAM
    .dynsym : { 
        *(.dynsym) 
    } > SRAM

    .got : {
        __simple_relocate_start = .;
        __got_start = .;
        * (.got*)
        __got_end = .;
    } > SRAM
    .data.rel : {
        __data_rel_start = .;
        * (.data.rel*)
        __data_rel_end = .;
        __simple_relocate_end = .;
    } > SRAM

    .data : ALIGN(6) {
        __init_array_start = .;
        __init_array_end = .;
        * (.data*)
        * (.sdata*)
    } > SRAM 

    .bss : ALIGN(6) {
        __bss_start = .;
        * (.sbss)
        * (.bss*)
        * (COMMON)
        . = ALIGN(4);
        __bss_end = .;
    } > SRAM

    .stack :
    {
        . = ALIGN(0x4);
        __stack_start = .;
        . += DEFINED(STACKSIZE) ? STACKSIZE : 0x200;
        __stack_end = .;
    } > SRAM

    __heap_start = .;
    end = .;

    /DISCARD/ : { *(.dynbss*) }
    /DISCARD/ : { *(.dynstr*) }
    /DISCARD/ : { *(.dynamic*) }
    /DISCARD/ : { *(.plt*) }
    /DISCARD/ : { *(.interp*) }
}

__SRAM_start = ADDR(.text);
__SRAM_size  = DEFINED(RAMSIZE) ? ADDR(.text)+RAMSIZE : ADDR(.text)+0x3000;
__data_vaddr = ADDR(.data);
__data_laddr = LOADADDR(.data);
__data_size  = SIZEOF(.data);
