# define a GDT
gdt_start:

# fist 8 bytes , null segment discriptor
gdt_null:
	.long 	0x0
	.long	0x0

gdt_code:
	# the code segment descriptor
	# base =0 x0 , limit =0 xfffff ,
	# 1 st flags : ( present )1 ( privilege )00 ( descriptor type )1 -> 1001 b
	# type flags : ( code )1 ( conforming )0 ( readable )1 ( accessed )0 -> 1010 b
	# 2 nd flags : ( granularity )1 (32 - bit default )1 (64 - bit seg )0 ( AVL )0 -> 1100 b
	.word 	0xffff 		#limit (bits 0-15)
	.word 	0x0  		#base  (bits 0-15)
	.byte 	0x0    		#base  (bits 16-23)
	.byte 	0b10011010 	#1 st flags , type flags
	.byte 	0b11001111   #2 nd flags , Limit ( bits 16 -19)
	.byte 	0x0  		#base  (bits 24-31)

gdt_data:
	.word 	0xffff
	.word 	0x0
	.byte 	0x0
	.byte 	0b10011010
	.byte 	0b11001111
	.byte 	0x0

gdt_end:

gdt_descriptor:
	.word	gdt_end - gdt_start - 1
	.long	gdt_start

.equ 	CODE_SEG,	gdt_code - gdt_start
.equ 	DATA_SEG,	gdt_data - gdt_start


