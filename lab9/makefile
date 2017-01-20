#target dependencies
#	rule to build
#		

all: prog

prog: stack.o queue.o lab9.o
	g++ stack.o queue.o lab9.o -o prog

lab9.o: lab9.cpp
	g++ -c lab9.cpp

stack.o: stack.cpp
	g++ -c stack.cpp

queue.o: queue.cpp
	g++ -c queue.cpp

clean: 
	rm *.o prog
