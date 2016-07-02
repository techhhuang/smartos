#ifndef _PIC_H
#define _PIC_H
#include <defs.h>
void init_pic();
void pic_enable(u8 irq);
void pic_send_eoi(u8 irq);

#endif