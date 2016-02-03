C=g++
CFLAGS=-c -Wall
SOURCES=main.cpp rshell.cpp

all: $(SOURCES)
	$(C) $(SOURCES)
