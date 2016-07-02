#include <smart/printk.h>
#include <smart/console.h>
#include <smart/irq.h>
#include <smart/keyboard.h>
#include <smart/timer.h>

void main () {
	clear_screen();
	printk("hello world!\n");
	init_irq();
	init_keyboard();
	init_timer();
	// int a=1/0;	
	printk("never printed\n");
}