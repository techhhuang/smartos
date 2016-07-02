#include <smart/irq.h>
#include <pic.h>
#include <idt.h>

void init_irq(){
	init_pic();
	init_idt();
}

void irq_set(u8 irq, u32 entry){
	set_irq_gate(T_IRQ0 + irq,entry);
}

void irq_enable(u8 irq){
	pic_enable(irq);
}

void irq_eoi(u8 irq){
	pic_send_eoi(irq);
}
