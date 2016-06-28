.code16

switch_to_pm:

	cli
	lgdt	gdt_descriptor
	movl	%cr0,	%eax
	or 		$0x1,	%eax
	movl	%eax,	%cr0	
	ljmp	$DATA_SEG,	$init_pm

.code32
init_pm:
	
	movw 	$DATA_SEG,	%ax
	movw 	%ax,	%ds 
	movw	%ax,	%es
	movw	%ax,	%gs 
	movw 	%ax,	%fs 
	movw	%ax,	%ss 

	movl	$0x90000,	%ebp
	movl	%ebp,	%esp
	call 	begin_pm

