.section .text  
.global _start  
.code16  

_start:  
    # movw    %cx,    %ax  
    # movw    %ax,    %ds  
    # movw    %ax,    %es  
  
    movw    $msgstr,%bp  
    movw    len,    %cx  
    call    print_string

.include "print_string.s"

msgstr:  
    .asciz  "Hello smartos  (print by BIOS int 0x10:0x13, mode 0x01)!\n\rthis is just a test"  
len:  
    .int    . - msgstr  
    .org    510  
    .word   0xaa55
    
