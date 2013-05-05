//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA3
//Due:			May 4, 2013
//Account		gp034
//----------------------------------------------------------------

using namespace std;
#include "DoubleHashTable.h"
#include <iostream>

DoubleHashTable::DoubleHashTable(int tableSize, int doubleHash){
	this->probeCount = 0;
	this->operationCount = 0;
	this->table = vector<HashEntry>(tableSize);
	this->tableSize = tableSize;
	this->doubleHash = doubleHash;
	for(int i = 0; i < tableSize; i++){
		this->table[i] = HashEntry();
	}
}