#include <sys/io.h>
#include <sys/defs.h>
#include <sys/string.h>
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5
#define COLOR	0x08
#define MAX_SCREEN_COL 80
#define MAX_SCREEN_ROW 25

int get_screen_offset(int row,int col){
	int offset=(MAX_SCREEN_ROW*row+col)*2;
	return offset;
}
int get_cursor(){
	outb(REG_SCREEN_CTRL,14);
	int offset = inb(REG_SCREEN_DATA)<<8;
	outb(REG_SCREEN_CTRL,15);
	offset+=inb(REG_SCREEN_DATA);
	return 2*offset;
}
void set_cursor(int offset){
	offset/=2;
	outb(REG_SCREEN_CTRL,14);
	outb(REG_SCREEN_DATA,(unsigned char)(offset>>8));
	outb(REG_SCREEN_CTRL,15);
	outb(REG_SCREEN_DATA,(unsigned char)(offset&0xff));
}

void print_char(unsigned char c,int row,int col){	
	unsigned char * video_memory = (unsigned char *) 0xb8000;
   	int offset=0;
	if(row>=0&&col>=0){
		offset=get_screen_offset(row,col);
	}else{
		offset=get_cursor();
	}
	if(c=='\n'){
		int rows=offset/(2*MAX_SCREEN_ROW);
		offset=get_screen_offset(rows,MAX_SCREEN_COL-1);

	}else{
		video_memory[offset] = c;
		video_memory[offset+1] = COLOR;
	}
	offset+=2;
	set_cursor(offset);
}
void clear_screen(){
	set_cursor(0);
	for(int i=0;i<MAX_SCREEN_COL*MAX_SCREEN_COL;i++){
		print_char(' ',-1,-1);
	}
	set_cursor(0);
}
void print_message(const char * message){
	size_t len=strlen(message);
	for(int i=0;i<len;i++){
		print_char(message[i],-1,-1);
	}
}

void main () {
	clear_screen();
	print_message("hello world!\nthis is a new row");	
}