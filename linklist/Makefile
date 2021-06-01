SHELL=/bin/bash
CC=gcc
CFLAGS=-g -Wall -I.
OBJ=linklist.o

# Build exec
all: linklist
linklist: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Build and run
exe: linklist
	./linklist

# Rules
%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean
clean:
	rm -f *.o *.a *.so linklist
