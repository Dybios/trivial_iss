IDIR = include/
CC = gcc
OBJ = cpurun.o
CFLAGS = -I$(IDIR)

INCLUDES = include/iss_api.h

all:
	$(CC) -g src/inst_decode.c src/runner.c $(INCLUDES) -o $(OBJ) $(CFLAGS)

clean:
	rm $(OBJ)
