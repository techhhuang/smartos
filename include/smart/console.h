#ifndef _CONSOLE_H
#define _CONSOLE_H

int get_screen_offset(int row,int col);
int get_cursor();
void set_cursor(int offset);
void console_write(unsigned char c,int row,int col,unsigned char color);
void clear_screen();

#endif