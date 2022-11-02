IDIR = include/
CC = gcc
OBJ = cpurun.o
CFLAGS = -I$(IDIR)

OUTFILES = bin/ramdump bin/regdump

INCLUDES = include/iss_api.h

all:
	$(CC) -g src/inst_decode.c src/runner.c $(INCLUDES) -o $(OBJ) $(CFLAGS)
	@touch bin/ramdump bin/regdump

clean:
	rm $(OBJ) $(OUTFILES)

.SILENT:clean
