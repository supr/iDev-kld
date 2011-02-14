#include <multiboot.h>
#include <video/video.h>

void loader_main(unsigned long magic, multiboot_info_t * mbi) {
	video_init();
	video_write_str_center("iDev ELF - Kernel Loader\n");
	video_set_fg_color(VGA_RED);
	video_write_str_center("Copyright (c) 2011 Prudhvi Krishna Surapaneni\n");
	video_write_line_char('-');
	video_set_fg_color(VGA_WHITE);
	video_write_str("Cmdline: ");
	video_set_fg_color(VGA_GREEN);
	video_write_str(mbi->cmdline);
}
