//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA2
//Due:			March 30, 2013
//Account		gp034
//----------------------------------------------------------------

#include "InsertionSort.h"

InsertionSort::InsertionSort(){}
void InsertionSort::Sort(vector<int> &source, int size){
	for(int i = 1; i < size; i++){
		int j = i;
		while(j > 0 && source[j - 1] > source[j]){
			this->Swap(source, j, j-1);
			j--;
		}
	}
}

void InsertionSort::Swap(vector<int> &source, int leftIndex, int rightIndex){
	int temp = source[leftIndex];
	source[leftIndex] = source[rightIndex];
	source[rightIndex] = temp;
}