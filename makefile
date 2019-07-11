all: utest

utest: Function.o main.o Dijkstra.o
	g++ Function.o Dijkstra.o main.o

Function.o: Function.cc
	g++ -c Function.cc -o Function.o
	
Dijkstra.o: Dijkstra.cc
	g++ -c Dijkstra.cc -o Dijkstra.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	rm *.o a.out kek.txt