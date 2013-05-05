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
#include <vector>
#include "HashTable.h"

class DoubleHashTable : public HashTable{
public:
	DoubleHashTable(int tableSize, int doubleHash);
protected:
	virtual int SearchForIndex(int key, bool searchDeleted, bool returnAvailableIndex){
		int probes = 0;
		int index = -1;
		int hash = this->Hash(key);
		int doubleHash = this->Jump(key);

		while(probes < this->tableSize){
			this->probeCount++;

			index = hash;
			while(index >= this->tableSize){
				index = index % this->tableSize;
			}

			if(!this->table[index].populated){
				return returnAvailableIndex ? index : -1;
			}
			else if(this->table[index].populated 
					&& this->table[index].deleted
					&& returnAvailableIndex){
				return index;
			}
			else if(this->table[index].populated 
					&& this->table[index].key == key){
				return this->table[index].deleted && !searchDeleted ? -1 : index;
			}

			hash += doubleHash;
			probes++;
		}

		return -1;
	}

	virtual int Hash(int key){
		return key % this->tableSize;
	}

	virtual int Jump(int key){
		return this->doubleHash - key % this->doubleHash;
	}
private:
	int doubleHash;
};