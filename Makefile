#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic

SOURCES= src/main.cpp src/base.cpp src/command.cpp src/composite.cpp src/rshell.cpp

#Targets

all:
	mkdir -p bin
	$(COMPILE) $(FLAGS) $(SOURCES) -o bin/rshell

rshell:
	mkdir -p bin
	$(COMPILE) $(FLAGS) $(SOURCES) -o bin/rshell

clean:
	rm bin/rshell
	rm -rf bin

