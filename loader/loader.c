#include <multiboot.h>
#include <video/video.h>

void loader_main(unsigned long magic, multiboot_info_t * mbi) {
	video_init();
	video_write_str_center("iDev ELF - Kernel Loader");
}
