#ifndef _IRQ_H
#define _IRQ_H

#include <defs.h>

void init_irq();

void set_irq(u8 index,u32 entry);

void enable_irq(u8 index);

#endif
