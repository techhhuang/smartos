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
	cat   $^ >$@;

run:build/os-image.bin
	qemu-system-i386 build/os-image.bin;