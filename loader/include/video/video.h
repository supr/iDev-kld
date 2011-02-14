#ifndef __IDEV_LD_VIDEO_VIDEO_H_
#define __IDEV_LD_VIDEO_VIDEO_H_

#define VGA_BLACK		0x00
#define VGA_BLUE		0x01
#define VGA_GREEN		0x02
#define VGA_CYAN		0x03
#define VGA_RED			0x04
#define VGA_MAGENTA		0x05
#define VGA_BROWN		0x06
#define VGA_LIGHT_GREY		0x07
#define VGA_DARK_GREY		0x08
#define VGA_LIGHT_BLUE		0x09
#define VGA_LIGHT_GREEN		0x0A
#define VGA_LIGHT_CYAN		0x0B
#define VGA_LIGHT_RED		0x0C
#define VGA_LIGHT_MAGENTA	0x0D
#define VGA_LIGHT_BROWN		0x0E
#define VGA_WHITE		0x0F

void video_write_line_char(char);
void video_set_fg_color(unsigned short);
void video_set_bg_color(unsigned short);
void video_write_char(char);
void video_write_str_center(const char *);
void video_write_str(const char *);
void video_clear_screen(void);
void video_init(void);

#endif
