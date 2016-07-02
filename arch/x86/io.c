#include <smart/io.h>

unsigned char inb(unsigned short port){
	unsigned char result;
	__asm__ __volatile__("in %%dx, %%al" : "=a" (result) : "d" (port));
	return result;
}

void outb(unsigned short port,unsigned char data){
	__asm__ __volatile__("out %%al, %%dx":: "a" (data) ,"d" (port));
}

