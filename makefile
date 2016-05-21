all: boot.img  
  
build/boot.o: boot.s  
	as -o $@ $<  
boot.img: boot.o  
	ld --oformat binary -N -Ttext 0x7c00 -o $@ $<  
  
# boot.img: boot  
# 	dd if=boot of=boot.img bs=512 count=1  
  
clean:  
	rm ./boot ./boot.img 

run:
	qemu-system-x86_64 boot.img