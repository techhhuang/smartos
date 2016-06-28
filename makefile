all: os-image.img

os-image.img:boot.img kernel.bin
	cat $^ >os-image.img
  
build/boot.o: boot.s  
	as -o $@ $<  
kernel_entry.o:kernel_entry.s
	as -o $@ $<
kernel.bin:kernel_entry.o kernal.o 
	ld --oformat binary -Ttext 0x1000 -o $@ $^
kernel.o:kernal.c
	gcc -ffreestanding -o $@ -c $<
boot.img: boot.o  
	ld --oformat binary -N -Ttext 0x7c00 -o $@ $<  
  
# boot.img: boot  
# 	dd if=boot of=boot.img bs=512 count=1  
  
clean:  
	-rm -rf ./boot ./boot.img ./*.o ./os-image.img  ./kernel.bin

run:
	qemu-system-i386 os-image.img
