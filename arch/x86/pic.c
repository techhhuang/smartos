#include <pic.h>
#include <smart/io.h>
#define IO_PIC1		0x20	// Master (IRQs 0-7)
#define IO_PIC2		0xA0	// Slave (IRQs 8-15)

#define IRQ_SLAVE	2		// IRQ at which slave connects to master
#define PIC_EOI		0x20	/* End-of-interrupt command code */

// Current IRQ mask
// Initial IRQ mask has interrupt 2 enabled (for slave 8259A)
static u16 irqmask = 0xFFFF & ~(1 << IRQ_SLAVE);

static void pic_set_mask(u16 mask) {
	irqmask = mask;
	outb(IO_PIC1 + 1, mask);
	outb(IO_PIC2 + 1, mask >> 8);
}

void pic_enable(u8 irq) {
	pic_set_mask(irqmask & ~(1<<irq));
}

void pic_send_eoi(u8 irq) {
	if(irq >= 8){
		outb(IO_PIC2,PIC_EOI);
	}
	outb(IO_PIC1,PIC_EOI);
}

void init_pic(void)
{
	/* Initialization of ICW1 */
	outb(0x20, 0x11);
	outb(0xA0, 0x11);

	/* Initialization of ICW2 */
	outb(0x21, 0x20);	/* start vector = 32 */
	outb(0xA1, 0x28);	/* start vector = 40 */

	/* Initialization of ICW3 */
	outb(0x21, 0x04);
	outb(0xA1, 0x02);

	/* Initialization of ICW4 */
	outb(0x21, 0x01);
	outb(0xA1, 0x01);

	/* mask interrupts */
	outb(0x21, 0xff);
	outb(0xA1, 0xff);
}