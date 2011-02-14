#include <string.h>
#include <video/video.h>

#define VGA_CHAR(c) ( c | (vga_char_attrib << 8) )
#define VGA(i,c) vga_base_addr[i] = VGA_CHAR(c)

static unsigned short * vga_base_addr;
static unsigned short vga_char_attrib;
static short vga_fg_color;
static short vga_bg_color;
static unsigned short c_x = 0;
static unsigned short c_y = 0;

void video_clear_screen(void) {
	for(int i = 0; i < (80 * 25); i++ )
		VGA(i,' ');		
}

void video_write_char(char ch) {
	
	switch(ch) {
		case '\r':
			c_x = 0;
			break;
		case '\n':
			c_x = 0;
			c_y++;
			break;
		case '\b':
			if(c_x != 0) c_x--;
			break;
		default:
			break;
	}

	if( ch >= ' ' ) {
		VGA( c_y * 80 + c_x , ch);
		c_x++;
	}

	if( c_x >= 80 ) {
		c_x = 0;
		c_y++;
	}
}

void video_write_str_center(const char * str) {
	size_t len = strlen(str) % 80;
	c_x = ( 80 - len )/2;
	video_write_str(str);
}

void video_write_str(const char * str) {
	for(int i = 0; i < strlen(str); i++) {
		video_write_char(str[i]);
	}
}

void video_init(void) {
	vga_base_addr = (unsigned short *)0xB8000;
	vga_fg_color = 0x09;
	vga_bg_color = 0x00;
	vga_char_attrib = ( vga_bg_color << 4) | ( vga_fg_color & 0x0F );
	video_clear_screen();
}
