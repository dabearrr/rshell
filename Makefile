C=g++
CFLAGS=-c -Wall
SOURCES=main.cpp rshell.cpp command.cpp

all: $(SOURCES)
	$(C) $(SOURCES)
