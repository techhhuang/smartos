load_disk:
	push	%dx
	movb	$0x02,	%ah
	movb	%dh,	%al
	movb	$0x00,	%ch
	movb 	$0x00,	%dh
	movb 	$0x02,	%cl 

	int 	$0x13 

	jc		disk_error

	pop 	%dx
	cmp		%al,	%dh
	jne		disk_error
	ret

disk_error:
	movw 	$DISK_ERROR_MSG,	%si 
	call 	bios_print
	jmp		.

DISK_ERROR_MSG:
	.asciz	"load disk error!"


