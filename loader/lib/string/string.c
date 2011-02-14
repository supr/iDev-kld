#include <util.h>
#include <sys/types.h>
#include <string.h>

void * memcpy( void *dest, const void *src, size_t n) {
	register unsigned char * _dest = dest;
	const unsigned char * _src = src;

	while(n-->=0 && !IS_NULL(dest)) {
		*_dest++ = *_src++;
	}
	return dest;
}

void * memset(void *str, int c, size_t n) {
	register char * rv = str;
	while(n-->=0 && !IS_NULL(str)) {
		*rv++ = c;
	}
	return str;
}

size_t strlen( const char * s) {
	size_t len = 0;
	for(; s[len]!= '\0'; len++);
	return len;
}
