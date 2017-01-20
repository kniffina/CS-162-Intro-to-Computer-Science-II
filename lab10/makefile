#target dependencies
#	rule to build
#

all: prog

prog: fibonacci.o lab10.o
	g++ fibonacci.o lab10.o -o prog

fibonacci.o: fibonacci.cpp	
	g++ -c fibonacci.cpp

lab10.o: lab10.cpp
	g++ -c lab10.cpp

clean:
	rm *.o prog
