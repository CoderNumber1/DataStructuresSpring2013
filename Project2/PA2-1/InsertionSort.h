//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA1
//Due:			March 30, 2013
//Account		gp034
//----------------------------------------------------------------

#include <vector>
using namespace std;

class InsertionSort{
public:
	InsertionSort();
	void Sort(vector<int> &source, int size);
private:
	void Swap(vector<int> &source, int left, int right);
};