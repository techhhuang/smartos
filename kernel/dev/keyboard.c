#include <smart/printk.h>
#include <smart/irq.h>
#include <smart/keyboard.h>
#include <smart/io.h>

static int is_normal_key_pressed(u8 data);
static int is_normal_key_released(u8 data);
static int is_special_key_released(u8 data);
static int is_special_key_pressed(u8 data);

void do_keyboad(){
	__asm__("cli");
	
	u8 code = inb(0x60);
	if(is_normal_key_pressed(code)){
		printk("%c",key_map[code]);
	}

	outb(0x20, 0x20);
	__asm__("sti");
}

void init_keyboard(){
	set_irq(33,(ptr_t)do_keyboad);
}

static int is_normal_key_pressed(u8 data) {
	if (key_map[data] != 0) // B pressed
		return 1;
	else
		return 0;
}

static int is_normal_key_released(u8 data) {
	if (key_map[data - 0x80] != 0) // B released, 0x32 is followed, but escape it first
		return 1;
	else
		return 0;
}

static int is_special_key_released(u8 data) {
	if (data == 0x9D || data == 0xAA || data == 0xB8) // Left Ctrl released, 0x14 is followed, but escape it first
		return 1;
	else
		return 0;
}

static int is_special_key_pressed(u8 data) {
	if (data == 0x1D || data == 0x2A || data == 0x38) // Left Ctrl pressed
		return 1;
	else
		return 0;
}
