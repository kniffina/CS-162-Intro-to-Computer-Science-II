#target dependencies
#	rule to build
#

all: prog

prog: item.o list.o main.o
	g++ item.o list.o main.o -o prog

main.o: main.cpp
	g++ -c main.cpp

item.o: item.cpp
	g++ -c item.cpp

list.o: list.cpp
	g++ -c list.cpp

clean: 
	rm *.o prog
