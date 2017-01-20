#target dependencies
#	rule to build
#

all: prog

prog: lab4.o main.o
	g++ lab4.o main.o -o prog

main.o: main.cpp
	g++ -c main.cpp

lab4.o: lab4.cpp
	g++ -c lab4.cpp

clean:
	rm *.o prog
