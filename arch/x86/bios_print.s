    # movb    $0x04,  %dh  #start row
    # movb    $0x08,  %dl  #start col
    # movb    $0x03,  %bl  #front color
    # movb    $0x00,  %bh  #page number

    # movb    $0x01,  %al  #cusor mode
    # movb    $0x13,  %ah  #int 0x10:0x13 print strings
    # int     $0x10  
    # ret

bios_print:
    lodsb
    or      %al,    %al     #zero=end of str
    jz      done            #get out
    mov     $0x0E,  %ah
    int     $0x10
    jmp     bios_print
done:
    ret