CC=gcc	#compiler used
CFLAGS=-Wall -std=c17 -I$(INCLPATH)	#options used by c compiler 
SRCPATH=../src#path for source file
INCLPATH=../include#path for the libraries
all: main
main: main.o game.o
	$(CC) $(CFLAGS) main.o game.o -o main 

main.o: $(SRCPATH)/main.c $(INCLPATH)/game.h
	$(CC) $(CFLAGS) -c $(SRCPATH)/main.c

game.o: $(SRCPATH)/game.c $(INCLPATH)/game.h
	$(CC) $(CFLAGS) -c $(SRCPATH)/game.c

clean:
	ifeq ($(OS),Windows_NT)
		del /Q *.o
	else
		rm -rf *.o
	endif

#versione semplificata
#all:
#	gcc -std=c17 -Wall ../src/*.c -I../include -o main 