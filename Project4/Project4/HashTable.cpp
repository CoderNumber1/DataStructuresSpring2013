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
#include "HashTable.h"
#include <iostream>

int HashTable::GetKey(int index){
	return this->table[index].key;
}

int HashTable::SearchForIndex(int key){
	return this->SearchForIndex(key, false, false);
	this->operationCount++;
}

void HashTable::Insert(int key){
	int index = this->SearchForIndex(key, true, true);
	if(index >= 0)
	{
		this->table[index].key = key;
		this->table[index].populated = true;
		this->table[index].deleted = false;
	}
	this->operationCount++;
}

void HashTable::Delete(int key){
	int index = this->SearchForIndex(key, true, false);
	if(index >= 0)
	{
		this->table[index].deleted = true;
	}
	this->operationCount++;
}

double HashTable::GetAverageProbeCount(){
	return ((double)this->probeCount)/this->operationCount;
}

int HashTable::GetTotalProbeCount(){
	return this->probeCount;
}

int HashTable::GetTotalOperationCount(){
	return this->operationCount;
}

void HashTable::PrintKeys(){
	for(int i = 0; i < this->tableSize; i++){
		if(this->table[i].populated){
			if(this->table[i].deleted){
				cout << "del";
			}
			else{
				cout << "ins";
			}

			cout << this->table[i].key << endl;
		}
	}
}

int HashTable::SearchForIndex(int key, bool searchDeleted, bool returnAvailableIndex){
	return -1;
}

int HashTable::Hash(int key){
	return -1;
}

int HashTable::Jump(int key){
	return -1;
}