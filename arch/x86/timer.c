#include <smart/io.h>
#include <smart/irq.h>

#define IO_TIMER1	0x40	// 8253 Timer #1

#define TIMER_FREQ	1193182
#define TIMER_DIV(x)	((TIMER_FREQ + (x)/2)/(x))

#define TIMER_MODE	(IO_TIMER1 + 3) // timer mode port
#define TIMER_SEL0	0x00	// select counter 0
#define TIMER_RATEGEN	0x04	// mode 2, rate generator
#define TIMER_16BIT	0x30	// r/w counter 16 bits, LSB first

void do_timer(){
	// __asm__("cli");
	
	//printk("timer");

	irq_eoi(IRQ_TIMER);

	 __asm__("sti");
}

void init_timer(void) {
	// Interrupt 100 times/sec
	outb(TIMER_MODE, TIMER_SEL0 | TIMER_RATEGEN | TIMER_16BIT);
	outb(IO_TIMER1, TIMER_DIV(20) % 256);
	outb(IO_TIMER1, TIMER_DIV(20) / 256);

	irq_set(IRQ_TIMER, (u32)do_timer);
	irq_enable(IRQ_TIMER);
}
