ARCH=x86
all:
	@echo "build boot binary...";
	make -C ./arch/${ARCH};
	@echo "build kernel binary...";
	make -C ./kernel;

clean:
	@echo "clean boot binary...";
	make -C ./arch/${ARCH} clean;
	@echo "clean kernel binary...";
	make -C ./kernel clean;
	rm -rf build/os-image.bin;

build/os-image.bin:./build/arch/${ARCH}/boot.bin ./build/kernel/kernel.bin
	# @dd if=/dev/zero of=build/os-image.bin bs=512 count=10;
	# @dd if=build/arch/${ARCH}/boot.bin of=build/os-image.bin bs=512 count=1;
	# @dd if=build/kernel/kernel.bin of=build/os-image.bin seek=1;
	cat   $^ >$@;

run:build/os-image.bin
	qemu-system-i386 build/os-image.bin -m 32;