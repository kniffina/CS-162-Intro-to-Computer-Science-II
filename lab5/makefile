#target dependencies
#	rule to build
#

all: prog

prog: goblin.o troll.o dragon.o icedragon.o firedragon.o lab5.o
	g++ goblin.o troll.o dragon.o icedragon.o firedragon.o lab5.o -o prog

lab5.o: lab5.cpp
	g++ -c lab5.cpp

goblin.o: goblin.cpp
	g++ -c goblin.cpp

troll.o: troll.cpp
	g++ -c troll.cpp

dragon.o: dragon.cpp
	g++ -c dragon.cpp

icedragon.o: icedragon.cpp
	g++ -c icedragon.cpp

firedragon.o: firedragon.cpp
	g++ -c firedragon.cpp

clean:
	rm *.o prog


