//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA3
//Due:			May 4, 2013
//Account		gp034
//----------------------------------------------------------------

#ifndef F03
#define F03 1

using namespace std;
#include <vector>

struct HashEntry{
public:
	HashEntry(){
		this->deleted = false;
		this->populated = false;
	}
	int key;
	bool deleted;
	bool populated;
};

class HashTable{
public:
	int GetKey(int index);
	int SearchForIndex(int key);
	void Insert(int key);
	void Delete(int key);
	double GetAverageProbeCount();
	int GetTotalProbeCount();
	int GetTotalOperationCount();
	void PrintKeys();
protected:
	virtual int Hash(int key);
	virtual int Jump(int key);
	virtual int SearchForIndex(int key, bool searchDeleted, bool returnAvailableIndex);

	vector<HashEntry> table;
	int tableSize;

	int probeCount;
	int operationCount;
};
#endif