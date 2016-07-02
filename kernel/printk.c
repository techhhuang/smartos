#include <string.h>
#include <smart/console.h>
#include <smart/printk.h>

#define MAX_BUF_SIZE 512

int printk(const char * format,...){
	va_list val;
	char message[MAX_BUF_SIZE] = {0};

	va_start(val, format);
	vsprintf(message, format, val);
	va_end(val);

	size_t len=strlen(message);
	for(int i=0;i<len;i++){
		console_write(message[i],-1,-1,0x03);
	}
}
