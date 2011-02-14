OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)
ENTRY(boot)
SECTIONS {
	.text 0x00100000:
	{
		code = .;
		*(.multiboot)
		*(.text)
		. = ALIGN(4096);
	}

	.data :
	{
		data = .;
		*(.data)
		*(.rodata)
		. = ALIGN(4096);
	}

	.bss :
	{
		bss = .;
		*(.bss)
		. = ALIGN(4096);
	}

	end = .;
}
