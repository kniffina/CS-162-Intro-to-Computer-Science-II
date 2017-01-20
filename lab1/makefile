#target dependencies
#	rule to build
#

all: prog

prog: readMatrix.o determinant.o main.o
	g++ readMatrix.o determinant.o main.o -o prog

main.o: main.cpp
	g++ -c main.cpp 

readMatrix.o: readMatrix.cpp
	g++ -c readMatrix.cpp

determinant.o: determinant.cpp
	g++ -c determinant.cpp

clean:
	rm *.o prog
