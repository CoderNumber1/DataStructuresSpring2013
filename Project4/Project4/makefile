all: pa4
pa4: removal Main.o DoubleHashTable.o QuadHashTable.o HashTable.o
	g++ -o pa4 Main.o DoubleHashTable.o QuadHashTable.o HashTable.o
Main.o: Main.cpp DoubleHashTable.h QuadHashTable.h HashTable.h
	g++ -c -g Main.cpp
QuadHashTable.o: QuadHashTable.cpp QuadHashTable.h HashTable.h
	g++ -c -g QuadHashTable.cpp
DoubleHashTable.o: DoubleHashTable.cpp DoubleHashTable.h HashTable.h
	g++ -c -g DoubleHashTable.cpp
HashTable.o: HashTable.cpp HashTable.h
	g++ -c -g HashTable.cpp
removal:
	rm -f *.o