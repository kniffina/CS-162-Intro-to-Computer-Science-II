#target dependencies
#	rule to build
#

all: prog

prog: die.o loadedDie.o game.o main.o
	g++ die.o loadedDie.o game.o main.o -o prog

main.o: main.cpp
	g++ -c main.cpp

die.o: die.cpp
	g++ -c die.cpp

loadedDie.o: loadedDie.cpp
	g++ -c loadedDie.cpp

game.o: game.cpp
	g++ -c game.cpp 

clean:
	rm *.o prog
