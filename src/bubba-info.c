#include "bubba-info.h"

#include <sys/utsname.h>
#include <stdint.h>
#include <string.h>

#define BUBBA_1 "armv4tl"
#define BUBBA_2 "ppc"
#define BUBBA_3 "armv5tel"

int getHWType(void) {
	struct utsname buf;
	uname( &buf );
	if( strcmp( buf.machine, BUBBA_1 ) == 0 ) {
		return 10;
	}
	if( strcmp( buf.machine, BUBBA_2 ) == 0 ) {
		return 20;
	}
	if( strcmp( buf.machine, BUBBA_3 ) == 0 ) {
		return 30;
	}
	return 0;
}

uint8_t isB1(void) {
	return getHWType() == 10;
}
uint8_t isB2(void) {
	return getHWType() == 20;
}
uint8_t isB3(void) {
	return getHWType() == 30;
}
