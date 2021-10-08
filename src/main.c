#include "bubba-info.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	int opt;
	while ((opt = getopt(argc, argv, ":123")) != -1) {
		switch (opt) {
		case '1':
				  return(isB1()==0);
		case '2':
				  return(isB2()==0);
		case '3':
				  return(isB3()==0);
		default: 
				  printf("Usage: %s [-123]\n", argv[0]);
				  return(0);
		}
	}
	printf( "%d\n", getHWType() );
	return 0;
}

