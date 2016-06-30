CC=gcc
FLAG= -ffreestanding  -fno-stack-protector -m32 $(INCDIR) -g
ASM=as 
ASMFLAG=--32
LD=ld
LDFLAG=  -m elf_i386  -T ${LINKER}
NM=nm
OBJDUMP=objdump
