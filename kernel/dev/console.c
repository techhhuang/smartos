#include <smart/console.h>
#include <smart/io.h>
#include <smart/mm.h>

#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5
#define BACKGROUND 0x0f
#define MAX_SCREEN_COL 80
#define MAX_SCREEN_ROW 25
#define VIDEO_ADDRESS 0xb8000

static unsigned char * video_memory = (unsigned char *) VIDEO_ADDRESS;

int get_screen_offset(int row,int col){
	int offset = (MAX_SCREEN_COL * row + col) * 2;
	return offset;
}
int get_cursor(){
	outb(REG_SCREEN_CTRL, 14);
	int offset = inb(REG_SCREEN_DATA) << 8;
	outb(REG_SCREEN_CTRL,15);
	offset += inb(REG_SCREEN_DATA);
	return 2 * offset;
}
void set_cursor(int offset){
	offset /= 2;
	outb(REG_SCREEN_CTRL, 14);
	outb(REG_SCREEN_DATA, (unsigned char)(offset >> 8));
	outb(REG_SCREEN_CTRL, 15);
	outb(REG_SCREEN_DATA, (unsigned char)(offset & 0xff));
}

int handle_scrolling(int offset)
{
	if(offset < MAX_SCREEN_COL*MAX_SCREEN_ROW*2){
		return offset;
	}

	for(int i = 1; i < MAX_SCREEN_ROW; i++){

		mem_copy((char *)(get_screen_offset(i,0) + VIDEO_ADDRESS),
				 (char *)(get_screen_offset(i-1,0) + VIDEO_ADDRESS),
				 MAX_SCREEN_COL * 2);
	}
	//clear last line
	char *last_line = (char *)(get_screen_offset(MAX_SCREEN_ROW - 1, 0)+VIDEO_ADDRESS);
	for(int i = 0; i < 2 * MAX_SCREEN_COL; i += 2){
		last_line[i] = 0;
		last_line[i+1] =BACKGROUND;
	}

	offset = offset - 2 * MAX_SCREEN_COL;

	return offset;
}

void console_write(unsigned char c,int row,int col,unsigned char color){	
	
   	int offset=0;
	if(row >= 0 && col >= 0){
		offset = get_screen_offset(row,col);
	}else{
		offset = get_cursor();
	}
	if(c == '\n'){
		int rows = offset / (2 * MAX_SCREEN_COL);
		offset = get_screen_offset(rows, MAX_SCREEN_COL - 1);

	}else{
		video_memory[offset] = c;
		video_memory[offset+1] = color;
	}
	offset += 2;

	offset = handle_scrolling(offset);

	set_cursor(offset);
}
void clear_screen(){
	set_cursor(0);

	for(int i = 0; i < MAX_SCREEN_ROW * MAX_SCREEN_COL; i++){
		console_write(' ', -1, -1, BACKGROUND);
	}

	set_cursor(0);
}

