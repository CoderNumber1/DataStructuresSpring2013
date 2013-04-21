all: pa3
pa3: removal main.o Graph.o RandomGen.o
	g++ -o pa3 main.o Graph.o RandomGen.o
main.o: main.cpp Graph.h RandomGen.h
	g++ -c -g main.cpp
Graph.o: Graph.cpp Graph.h
	g++ -c -g Graph.cpp
RandomGen.o: RandomGen.cpp RandomGen.h
	g++ -c -g RandomGen.cpp
removal:
	rm -f *.o