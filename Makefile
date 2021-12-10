# -*- MakeFile -*-
CC=g++ -g -std=c++17
CFLAGS=-I.

all: main
	./main

main: main.o shell.o util.o cd.o runCommand.o
	$(CC) main.o shell.o util.o runCommand.o cd.o -o main

main.o: main.cpp main.h shell.h
	$(CC) -c main.cpp

shell.o: shell.cpp util.h shell.h
	$(CC) -c shell.cpp

util.o: util.cpp util.h
	$(CC) -c util.cpp

cd.o: cd.cpp shell.h util.h
	$(CC) -c cd.cpp

runCommand.o: runCommand.cpp
	${CC} -c runCommand.cpp

cd.o: cd.cpp
	${CC} -c cd.cpp

# debug.o: debug.cpp debug.h
# 	$(cc) -c debug.cpp

clean:
	rm *.o main
