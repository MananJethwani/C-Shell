# -*- MakeFile -*-
CC=g++ -std=c++17
CFLAGS=-I.

all: main
	./main

main: main.o shell.o util.o cd.o runCommand.o pwd.o echo.o envVariables.o ls.o
	$(CC) main.o shell.o util.o runCommand.o cd.o pwd.o echo.o envVariables.o ls.o -o main

main.o: main.cpp main.h shell.h
	$(CC) -c main.cpp

shell.o: shell.cpp util.h shell.h
	$(CC) -c shell.cpp

util.o: util.cpp util.h
	$(CC) -c util.cpp

cd.o: cd.cpp shell.h util.h
	$(CC) -c cd.cpp

pwd.o: pwd.cpp shell.h util.h
	${CC} -c pwd.cpp

runCommand.o: runCommand.cpp
	${CC} -c runCommand.cpp

cd.o: cd.cpp
	${CC} -c cd.cpp

ls.o: ls.cpp
	${CC} -c ls.cpp

echo.o: echo.cpp
	${CC} -c echo.cpp

envVariables.o: envVariables.cpp shell.h util.h
	${CC} -c envVariables.cpp

# debug.o: debug.cpp debug.h
# 	$(cc) -c debug.cpp

clean:
	rm *.o main
