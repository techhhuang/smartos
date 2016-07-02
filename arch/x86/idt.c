#include <idt.h>
#include <smart/printk.h>

#define exception_handler_func(n)	\
	void exception_handler_##n (void) { printk("exception :\n");}

#define exception_handler(n)	\
	exception_handler_##n

exception_handler_func(0)

idt_entry_t idt_entries[255];
idtr_t _idtr;


void set_trap_gate(u8 index,u32 offset)
{
	idt_entries[index].offset0_15 = (offset & 0xffff);
	idt_entries[index].segment = 0x08;
	idt_entries[index].reserved = 0;
	idt_entries[index].flags = 0x8f;
	idt_entries[index].offset16_31 = (offset >>16) & 0xffff;
	return;
}
void set_irq_gate(u8 index,u32 offset)
{
	idt_entries[index].offset0_15 = (offset & 0xffff);
	idt_entries[index].segment = 0x08;
	idt_entries[index].reserved = 0;
	idt_entries[index].flags = 0x8e;
	idt_entries[index].offset16_31 = (offset >>16) & 0xffff;
	return;
}



void init_idt(){
	_idtr.limit = sizeof(idt_entry_t)*255-1;
	_idtr.base = (ptr_t)&idt_entries;
    
    for(int i = 0; i < 31; i++){
		set_trap_gate(0,(ptr_t)exception_handler(0));
    }
	
	// set_irq_gate(32,(ptr_t)irq0);
	// set_irq_gate(33,(ptr_t)irq1);

	__asm__("lidt (_idtr)");	
}