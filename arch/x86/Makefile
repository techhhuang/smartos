BUILDDIR=../../build/arch/x86

all:${BUILDDIR}/boot.bin
	@echo "build boot binary";
${BUILDDIR}/boot.bin: ${BUILDDIR}/boot.o  
	ld --oformat binary -N -Ttext 0x7c00 -o $@ $< 
${BUILDDIR}/boot.o: boot.s  
	as -o $@ $<  
clean:
	rm -rf ${BUILDDIR}/*.o;
	rm -rf ${BUILDDIR}/boot.bin;
 