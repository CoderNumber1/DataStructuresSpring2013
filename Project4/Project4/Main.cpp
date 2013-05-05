//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA3
//Due:			April 20, 2013
//Account		gp034
//----------------------------------------------------------------

#include "HashTable.h"
#include "DoubleHashTable.h"
#include "QuadHashTable.h"
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct HashTableSummary{
public:
	HashTableSummary(){
		this->averageProbeCount = 0;
		this->totalProbeCount = 0;
		this->totalOperationCount = 0;
		this->keysInsertedCount = 0;
		this->keysDeletedCount = 0;
	}

	double averageProbeCount;
	int totalProbeCount;
	int totalOperationCount;
	int keysInsertedCount;
	int keysDeletedCount;
};

HashTableSummary PopulateDoubleHash(istream& inputFile, HashTable& hashTable){
	HashTableSummary result = HashTableSummary();

	for(;;){
		char operation;
		int key;

		inputFile >> operation;
		inputFile >> key;

		if(operation == 'i'){
			result.keysInsertedCount++;
			hashTable.Insert(key);
		}
		else if(operation == 'r'){
			result.keysDeletedCount ++;
			hashTable.Delete(key);
		}

		if(inputFile.eof())
			break;
	}

	result.averageProbeCount = hashTable.GetAverageProbeCount();
	result.totalProbeCount = hashTable.GetTotalProbeCount();
	result.totalOperationCount = hashTable.GetTotalOperationCount();

	return result;
}

int main(int argc, char* argv[]){
	try{
		int tableSize = atoi(argv[1]);
		int doubleHash = atoi(argv[2]);
		int c1 = atoi(argv[3]);
		int c2 = atoi(argv[4]);
		
		ifstream doubleInputFile("Input.txt");
		DoubleHashTable doubleTable(tableSize, doubleHash);
		HashTableSummary doubleSummary = PopulateDoubleHash(doubleInputFile, doubleTable);
		doubleInputFile.close();

		cout << "Double Summary" << endl;
		cout << "Total Probe Count: " << doubleSummary.totalProbeCount << endl;
		cout << "Total Operation Count: " << doubleSummary.totalOperationCount << endl;
		cout << "Average Probe Count: " << doubleSummary.averageProbeCount << endl;
		cout << "Keys Inserted Count: " << doubleSummary.keysInsertedCount << endl;
		cout << "Keys Deleted Count: " << doubleSummary.keysDeletedCount << endl;
		cout << endl;

		ifstream quadInputFile("Input.txt");
		QuadHashTable quadTable(tableSize, c1, c2);
		HashTableSummary quadSummary = PopulateDoubleHash(quadInputFile, quadTable);
		quadInputFile.close();

		cout << "Quadratic Summary" << endl;
		cout << "Total Probe Count: " << quadSummary.totalProbeCount << endl;
		cout << "Total Operation Count: " << quadSummary.totalOperationCount << endl;
		cout << "Average Probe Count: " << quadSummary.averageProbeCount << endl;
		cout << "Keys Inserted Count: " << quadSummary.keysInsertedCount << endl;
		cout << "Keys Deleted Count: " << quadSummary.keysDeletedCount << endl;
		cout << endl;
	}
	catch(...){
		cout << endl;
		cout << "Program ended unexpectedly.";
		cout << endl;

		exit(EXIT_FAILURE);
	}
}