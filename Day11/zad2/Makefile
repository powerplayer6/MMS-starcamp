CC=gcc #sets which compiler to use

.PHONY: all #lets makefile not care about file not existing
all: program #starts compilation

program: zad2.o comparators.o #compiles the main file and the functions file into an executable
	$(CC) zad2.o comparators.o -o zad2

main.o: zad2.c comparators.h #creates object code file for the main file of the program
	$(CC) -c zad2.c -o zad2.o

hello.o: comparators.c #creates object code file for the functions file of the program
	$(CC) -c comparators.c -o comparators.o

.PHONY: clean #lets makefile not care about file not existing
clean: #cleans up created object code files and executable
	rm *.o zad2