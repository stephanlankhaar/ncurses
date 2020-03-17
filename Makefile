CC=g++

all: Hello

%.o: %.c %.h
	$(CC) -c $^ -lncurses

Hello:attributes.o hello.o helloWorld.o menu.o test.o testUserInput.o testUserMovement.o userInputExample.o Window.o
	$(CC) -o $@ $^ -lncurses
