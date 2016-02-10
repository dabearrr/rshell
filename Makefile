#Variables
COMPILE = g++
FLAGS = #-g -W -Wall -Werror -ansi -pedantic
OBJS = command.o composite.o base.o rshell.o

#Targets

all: main.cpp $(OBJS)
	$(COMPILE) $(FLAGS) -o a.out main.cpp $(OBJS)

command.o: command.cpp command.h
	$(COMPILE) $(FLAGS) -c command.cpp

composite.o: composite.cpp composite.h 
	$(COMPILE) $(FLAGS) -c composite.cpp

base.o: base.cpp base.h 
	$(COMPILE) $(FLAGS) -c base.cpp
	
rshell.o: rshell.cpp rshell.h
	$(COMPILE) $(FLAGS) -c rshell.cpp

clean:
	rm -rf *~ *.o a.out

