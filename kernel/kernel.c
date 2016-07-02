#include <smart/printk.h>
#include <smart/console.h>
#include <smart/irq.h>
#include <smart/keyboard.h>

void main () {
	clear_screen();
	printk("hello world!\n");
	init_irq();
	init_keyboard();
	// int a=1/0;	
	printk("never printed\n");
}