#include <stdio.h>
#include <sys/pic.h>
#include <sys/idt.h>

void main () {
	clear_screen();
	printf("hello world!\n");
	printf("h\n");
	printf("h\n");
	init_pic();
	init_idt();
	int a=1/0;	
	while(1);
	printf("never printed\n");	
}