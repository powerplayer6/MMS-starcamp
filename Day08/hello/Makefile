CC=g++

.PHONY: all
all: program

program: main.o hello.o
	$(CC) main.o hello.o -o program

main.o: main.c hello.h
	$(CC) -c main.c -o main.o

hello.o: hello.c
	$(CC) -c hello.c -o hello.o

.PHONY: clean
clean:
	rm *.o program