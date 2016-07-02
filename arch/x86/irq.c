#include <smart/irq.h>
#include <pic.h>
#include <idt.h>

void init_irq(){
	init_pic();
	init_idt();
}

void set_irq(u8 index, u32 entry){
	set_irq_gate(index,entry);
}
