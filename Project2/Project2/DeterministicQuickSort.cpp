//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA2
//Due:			March 30, 2013
//Account		gp034
//----------------------------------------------------------------

#include "DeterministicQuickSort.h"

using namespace std;

DeterministicQuickSort::DeterministicQuickSort(){}
void DeterministicQuickSort::Sort(vector<int> &source, int size){
	this->Sort(source, 0, size - 1);
}

void DeterministicQuickSort::Sort(vector<int> &source, int low, int high){
	if(low < high){
		int pivotIndex = this->Partition(source, low, high);
		this->Sort(source, low, pivotIndex - 1);
		this->Sort(source, pivotIndex + 1, high);
	}
}

int DeterministicQuickSort::Partition(vector<int> &source, int low, int high){
	int pivot = source[low];
	int i = low;
	for(int j = low + 1; j <= high; j++){
		if(source[j] <= pivot){
			i++;
			this->Swap(source, i, j);
		}
	}

	this->Swap(source, low, i);

	return i;
}

void DeterministicQuickSort::Swap(vector<int> &source, int leftIndex, int rightIndex){
	int temp = source[leftIndex];
	source[leftIndex] = source[rightIndex];
	source[rightIndex] = temp;
}