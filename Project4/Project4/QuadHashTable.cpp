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
#include "QuadHashTable.h"
#include <iostream>

QuadHashTable::QuadHashTable(int tableSize, int c1, int c2){
	this->probeCount = 0;
	this->operationCount = 0;
	this->table = vector<HashEntry>(tableSize);
	this->tableSize = tableSize;
	this->c1 = c1;
	this->c2 = c2;
	for(int i = 0; i < tableSize; i++){
		this->table[i] = HashEntry();
	}
}