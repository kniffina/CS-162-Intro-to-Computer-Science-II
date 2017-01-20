#target dependencies
#	rule to build
#

all: prog

prog: stack.o queue.o lab6.o
	g++ stack.o queue.o lab6.o -o prog

lab6.o: lab6.cpp
	g++ -c lab6.cpp

stack.o: stack.cpp
	g++ -c stack.cpp

queue.o: queue.cpp
	g++ -c queue.cpp

clean:
	rm *.o prog
