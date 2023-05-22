CC = gcc
CFLAGS = -Wall -g

all: program

program: main.o findA.o findB.o input.o
	$(CC) $(CFLAGS) -o program main.o findA.o findB.o input.o -lm

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

findA.o: findA.c header.h
	$(CC) $(CFLAGS) -c findA.c

findB.o: findB.c header.h
	$(CC) $(CFLAGS) -c findB.c

input.o: input.c header.h
	$(CC) $(CFLAGS) -c input.c

clean:
	rm -f program *.o

