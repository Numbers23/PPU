CC   = gcc
CFLAGS = -O2 -DLSB_FIRST -DDEBUG

process:   process.c
	${CC} -o ppu process.c

ppu.o:   ppu.c ppu.h
