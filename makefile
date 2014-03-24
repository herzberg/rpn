CC = gcc
CFLAGS = -wall

all: calc
	./calc
	
calc: calc.o rpneval.o
	$(CC) $(CFLAGS) -o calc calc.o rpneval.o
	
calc.o: calc.c rpneval.h
	$(CC) $(CFLAGS) -c calc.c
	
rpneval.o: rpneval.c rpneval.h
	$(CC) $(CFLAGS) -c rpneval.c

	

	

