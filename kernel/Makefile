ARCH?=x86
BUILDDIR=../build/kernel
ARCHDIR=../build/arch/${ARCH}
INCDIR= -I ../include -I .
LINKER=./linker.ld

include ../arch/${ARCH}/config.make

SOURCES=$(wildcard ./*.c ./dev/*.c)
OBJS=${SOURCES:%.c=${BUILDDIR}/%.o}

OBJS+=$(wildcard ${ARCHDIR}/*.o)


all:${BUILDDIR}/kernel.bin

${BUILDDIR}/kernel.bin:	${BUILDDIR}/kernel_entry.o	${OBJS}
	${LD} ${LDFLAG}  -o $@ $^ 

${BUILDDIR}/%.o:%.s
	${ASM} ${ASMFLAG} -o $@ $< 

${BUILDDIR}/%.o:%.c ${HEADERS}
	${CC} ${FLAG} -o $@ -c $< 

clean:
	rm -rf ${BUILDDIR}/*.o;
	rm -rf ${BUILDDIR}/kernel.bin;