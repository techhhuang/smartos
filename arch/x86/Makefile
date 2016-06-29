BUILDDIR=../../build/arch/x86
INCDIR= -I ../../include -I .
LINKER=./linker.ld

include ./config.make

SOURCES=$(wildcard ./*.c)
OBJS=${SOURCES:%.c=${BUILDDIR}/%.o}

all:${BUILDDIR}/boot.bin
	@echo "build boot binary";

${BUILDDIR}/boot.bin: ${BUILDDIR}/boot.o  ${OBJS}
	${LD} ${LDFLAG}  -o $@ $< 

${BUILDDIR}/%.o:%.s
	${ASM} ${ASMFLAG} -o $@ $< 

${BUILDDIR}/%.o:%.c ${HEADERS}
	${CC} ${FLAG} -o $@ -c $< 

clean:
	rm -rf ${BUILDDIR}/*.o;
	rm -rf ${BUILDDIR}/boot.bin;
 