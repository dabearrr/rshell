#Variables
COMPILE = g++
FLAGS = -g -W -Wall -Werror -ansi -pedantic

SOURCES= src/main.cpp

#Targets

all:
	mkdir -p bin
	$(COMPILE) $(FLAGS) $(SOURCES) -o bin/a.out

clean:
	rm bin/a.out
	rm -rf bin

