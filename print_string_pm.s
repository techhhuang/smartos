.code32
#Define some constants
.equ 	VIDEO_MEMORY,	0xb8000
.equ 	COLOR, 0x0f

#prints a null - terminated string pointed to by EDX
print_string_pm:
	pusha
	movl 	$VIDEO_MEMORY,	%edx 

print_string_pm_loop :
	mov 	(%ebx),		%al				#Store the char at EBX in AL
	mov 	$COLOR,		%ah 			#Store the attributes in AH
	cmp 	$0,			%al
	je 		print_string_pm_done 		# if ( al == 0) , at end of string , so jump to done
	mov 	%ax,		(%edx)
	add 	$1,			%ebx
	add 	$2,			%edx
	jmp 	print_string_pm_loop

print_string_pm_done :
	popa
	ret
