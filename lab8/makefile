#target dedendencies
#	rule to build
#

all: prog

prog: queue.o lab8.o
	g++ queue.o lab8.o -o prog

queue.o: queue.cpp
	g++ -c queue.cpp

lab8.o: lab8.cpp
	g++ -c lab8.cpp

clean:
	rm *.o prog
