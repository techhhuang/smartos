BUILDDIR=../build/kernel

SOURCES=$(wildcard ./*.c)
HEADERS=$(wildcard ./*.h)
OBJS=${SOURCES:%.c=${BUILDDIR}/%.o}


all:${BUILDDIR}/kernel.bin

${BUILDDIR}/kernel.bin:	${BUILDDIR}/kernel_entry.o	${OBJS}
	ld --oformat binary -Ttext 0x1000 -o $@ $^

${BUILDDIR}/%.o:%.s
	as -o $@ $<

${BUILDDIR}/%.o:%.c ${HEADERS}
	gcc -ffreestanding -o $@ -c $<

clean:
	rm -rf ${BUILDDIR}/*.o;
	rm -rf ${BUILDDIR}/kernel.bin;