# -*- MakeFile -*-
CC=g++ -std=c++17
CFLAGS=-I.

all: main
	./main

main: main.o shell.o util.o 
	$(CC) main.o shell.o util.o -o main

main.o: main.cpp main.h shell.h
	$(CC) -c main.cpp

shell.o: shell.cpp util.h shell.h 
	$(CC) -c shell.cpp

util.o: util.cpp util.h
	$(CC) -c util.cpp

# debug.o: debug.cpp debug.h
# 	$(cc) -c debug.cpp

clean:
	rm *.o main
