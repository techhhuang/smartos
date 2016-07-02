#include <pic.h>
#include <smart/io.h>
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
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
}