#ifndef _IDT_H
#define _IDT_H
#include <sys/defs.h>

struct idtr {
	u16 limit;
	u32 base;
} __attribute__ ((packed));

typedef struct idtr idtr_t;

struct idt_entry {
	u16 offset0_15;
	u16 segment;
	u8 reserved;
	u8 flags;
	u16 offset16_31;
} __attribute__ ((packed));

typedef struct idt_entry idt_entry_t;
void init_idt();
void init_idt_entry(u8 index,u32 offset, u16 segment, u16 flags);
#endif