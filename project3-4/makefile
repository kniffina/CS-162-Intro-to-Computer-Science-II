#target dependencies
#	rule to build
#

all: prog

prog: barbarian.o bluemen.o creature.o harrypotter.o medusa.o stack.o vampire.o assignment4.o
	g++ barbarian.o bluemen.o creature.o harrypotter.o medusa.o stack.o vampire.o assignment4.o -o prog

barbarian.o: barbarian.cpp
	g++ -c barbarian.cpp

bluemen.o: bluemen.cpp
	g++ -c bluemen.cpp

creature.o: creature.cpp
	g++ -c creature.cpp

harrypotter.o: harrypotter.cpp
	g++ -c harrypotter.cpp

medusa.o: medusa.cpp
	g++ -c medusa.cpp

stack.o: stack.cpp
	g++ -c stack.cpp

vampire.o: vampire.cpp
	g++ -c vampire.cpp

assignment4.o: assignment4.cpp
	g++ -c assignment4.cpp

clean:
	rm *.o prog
