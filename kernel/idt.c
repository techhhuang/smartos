#include <sys/idt.h>
#include <stdio.h>

#define exception_handler_func(n)	\
	void exception_handler_##n (void) { printf("exception :\n");}

#define exception_handler(n)	\
	exception_handler_##n

exception_handler_func(0)
exception_handler_func(1)
exception_handler_func(2)
exception_handler_func(3)
exception_handler_func(4)
exception_handler_func(5)
exception_handler_func(6)
exception_handler_func(7)
exception_handler_func(8)
exception_handler_func(9)
exception_handler_func(10)
exception_handler_func(11)
exception_handler_func(12)
exception_handler_func(13)
exception_handler_func(14)
exception_handler_func(15)
exception_handler_func(16)
exception_handler_func(17)
exception_handler_func(18)
exception_handler_func(19)
exception_handler_func(20)
exception_handler_func(21)
exception_handler_func(22)
exception_handler_func(23)
exception_handler_func(24)
exception_handler_func(25)
exception_handler_func(26)
exception_handler_func(27)
exception_handler_func(28)
exception_handler_func(29)
exception_handler_func(30)
exception_handler_func(31)

idt_entry_t idt_entries[256];
idtr_t _idtr;

void init_idt_entry(u8 index,u32 offset, u16 segment, u16 flags)
{
	idt_entries[index].offset0_15 = (offset & 0xffff);
	idt_entries[index].segment = segment;
	idt_entries[index].reserved = 0;
	idt_entries[index].flags = flags;
	idt_entries[index].offset16_31 = (offset >>16) & 0xffff;
	return;
}

void init_idt(){
	_idtr.limit = sizeof(idt_entry_t)*256-1;
	_idtr.base = (ptr_t)&idt_entries;

	init_idt_entry(0,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(1,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(2,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(3,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(4,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(5,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(6,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(7,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(8,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(9,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(10,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(11,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(12,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(13,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(14,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(15,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(16,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(17,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(18,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(19,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(20,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(21,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(22,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(23,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(24,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(25,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(26,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(27,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(28,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(29,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(30,(ptr_t)exception_handler(0),0x08,0x8f);
	init_idt_entry(31,(ptr_t)exception_handler(0),0x08,0x8e);
	init_idt_entry(32,(ptr_t)exception_handler(0),0x08,0x8e);

	__asm__("lidt (_idtr)");	
}