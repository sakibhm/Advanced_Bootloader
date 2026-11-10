ENTRY(reset_handler)

stack = 0x20020000;

MEMORY
{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 32K
    RAM(rwx)  : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .vector_table :
    {
        KEEP(*(.vector_table))
    } > FLASH

    .text :
    {
        *(.text.reset_handler)
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT> FLASH

    _sidata = LOADADDR(.data);

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM
}
