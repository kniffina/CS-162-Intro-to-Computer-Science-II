#target dependencies
#	rule to build
#

all: prog

prog: copy.o compare.o createDesign.o display.o main.o
	g++ copy.o compare.o createDesign.o display.o main.o -o prog

main.o: main.cpp
	g++ -c main.cpp

copy.o: copy.cpp
	g++ -c copy.cpp

compare.o: compare.cpp
	g++ -c compare.cpp

createDesign.o: createDesign.cpp
	g++ -c createDesign.cpp

display.o: display.cpp
	g++ -c display.cpp

clean:
	rm *.o prog 
