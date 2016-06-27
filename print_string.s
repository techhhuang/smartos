print_string:
    movb    $0x04,  %dh  #start row
    movb    $0x08,  %dl  #start col
    movb    $0x03,  %bl  #front color
    movb    $0x00,  %bh  #page number

    movb    $0x01,  %al  #cusor mode
    movb    $0x13,  %ah  #int 0x10:0x13 print strings
    int     $0x10  
    ret
    # movb    $0x01,  %al  #set current show page
    # movb    $0x05,  %ah
    # int     $0x10