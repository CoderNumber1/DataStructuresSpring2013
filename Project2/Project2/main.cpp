//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA1
//Due:			March 30, 2013
//Account		gp034
//----------------------------------------------------------------

#include "DeterministicQuickSort.h"
#include "RandomGen.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	//ofstream output("QuickToInsertionOutput.csv");
	//DeterministicQuickSort quickSorter;
	//InsertionSort insertionSorter;
	//output << "dataset,type,size,time,output" << endl;
	//for(int i = 50; i <= 500; i+=50){
	//	vector<int> quickSource(i);
	//	vector<int> insertionSource(i);

	//	for(int j = 0; j < i; j++){
	//		int value = RandomGen::GetInstance().GetRandom(0, i);
	//		quickSource[j] = value;
	//		insertionSource[j] = value;
	//		//For Debug Only
	//		/*if(j >= 1){
	//			output << "|";
	//		}
	//		output << value;*/
	//	}
	//	/*output << endl;*/
	//	
	//	output << ",Quick Sort," << i << ",";
	//	std::clock_t quickTime = std::clock();
	//	quickSorter.Sort(quickSource, quickSource.size());
	//	output << std::setprecision(15) << (std::clock() - quickTime)/(double)CLOCKS_PER_SEC << ",";
	//	//For Debug Only
	//	/*for(int j = 0; j < quickSource.size(); j++){
	//		if(j >= 1){
	//			output << "|";
	//		}
	//		output << quickSource[j];
	//	}*/
	//	output << endl;

	//	output << ",Insertion Sort," << i << ",";
	//	std::clock_t insertionTime = std::clock();
	//	insertionSorter.Sort(insertionSource, insertionSource.size());
	//	output << std::setprecision(15) << (std::clock() - insertionTime)/(double)CLOCKS_PER_SEC << ",";
	//	//For Debug Only
	//	/*for(int j = 0; j < insertionSource.size(); j++){
	//		if(j >= 1){
	//			output << "|";
	//		}
	//		output << insertionSource[j];
	//	}*/
	//	output << endl;
	//}
	//output.close();
}