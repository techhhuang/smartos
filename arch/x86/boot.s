.global _start 
.section .text 
.code16  

.equ KERNEL_OFFSET,  0x1000

_start:  
    
    movb    %dl,    BOOT_DRIVE
    movw    $0x9000,    %bp 
    movw    %bp,    %sp

    movw    $MSG_REAL_MDOE,    %si  
    call    bios_print
    call    load_kernel
    call    switch_to_pm
    jmp     .

.include    "bios_print.s"
.include    "gdt.s"
.include    "load_disk.s"

load_kernel:
    movw    $MSG_LOAD_KERNEL,   %si
    call    bios_print
    movw    $KERNEL_OFFSET,     %bx
    movb    $10,    %dh
    movb    BOOT_DRIVE, %dl
    call    load_disk
    ret

switch_to_pm:
    cli
    lgdt    gdt_descriptor
    movl    %cr0,   %eax
    or      $0x1,   %eax
    movl    %eax,   %cr0    
    ljmp    $CODE_SEG,  $init_pm

.code32
init_pm:
    movw    $DATA_SEG,  %ax
    movw    %ax,    %ds 
    movw    %ax,    %es
    movw    %ax,    %gs 
    movw    %ax,    %fs 
    movw    %ax,    %ss
   
    movl    $0x90000,   %ebp
    movl    %ebp,   %esp
    call    begin_pm

begin_pm:

    movl    $MSG_PM_MODE,   %ebx
    call    print_string_pm
    call    KERNEL_OFFSET
    jmp     .


.include    "print_string_pm.s"


BOOT_DRIVE:
    .byte   0
MSG_REAL_MDOE:  
    .ascii  "----this is printed from real mode\n\r"
    .asciz  "----begin to load smart os kernel\n\r"
MSG_PM_MODE:
    .asciz  "----this is printed from protected mode\n\r"
MSG_LOAD_KERNEL:
    .asciz  "----loading kernel into memory...\n\r"

    .org    510  
    .word   0xaa55
    
