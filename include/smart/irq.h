#ifndef _IRQ_H
#define _IRQ_H

#include <defs.h>

#define T_IRQ0		32	// IRQ 0 corresponds to int T_IRQ
#define IRQ_TIMER 0
#define IRQ_KEYBOARD 1

void init_irq();

void irq_set(u8 irq,u32 entry);

void irq_enable(u8 irq);

void irq_eoi(u8 irq);

#endif
