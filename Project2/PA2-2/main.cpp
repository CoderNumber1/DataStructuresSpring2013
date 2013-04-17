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
#include "RandomQuickSort.h"
#include "RandomGen.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	ofstream output("DeterminateToRandomQuickSortRandomData.csv");
	DeterministicQuickSort quickSorter;
	RandomQuickSort randomQuickSorter;
	output << "dataset,type,size,time,output" << endl;
	for(int i = 50; i <= 500; i+=50){
		vector<int> quickSource(i);
		vector<int> randomQuickSource(i);

		for(int j = 0; j < i; j++){
			int value = RandomGen::GetInstance().GetRandom(0, i);
			quickSource[j] = value;
			randomQuickSource[j] = value;
		}
		
		output << ",Quick Sort," << i << ",";
		std::clock_t quickTime = std::clock();
		quickSorter.Sort(quickSource, quickSource.size());
		output << std::setprecision(15) << (std::clock() - quickTime)/(double)CLOCKS_PER_SEC << ",";
		output << endl;

		output << ",Randomized Quick Sort," << i << ",";
		std::clock_t randomQuickTime = std::clock();
		randomQuickSorter.Sort(randomQuickSource, randomQuickSource.size());
		output << std::setprecision(15) << (std::clock() - randomQuickTime)/(double)CLOCKS_PER_SEC << ",";
		output << endl;
	}
	output.close();

	ofstream partialSortOutput("DeterminateToRandomQuickSortPartialSortedOutput.csv");
	partialSortOutput << "dataset,type,size,time,output" << endl;
	for(int i = 50; i <= 500; i+=50){
		int twoThirds = (i*3)/4;
		vector<int> quickSource(i);
		vector<int> randomQuickSource(i);

		for(int h = 0; h <= twoThirds; h++){
			int value = h; //We want half of each list to be in order
			quickSource[h] = value;
			randomQuickSource[h] = value;
		}

		for(int j = twoThirds + 1; j < i; j++){
			int value = RandomGen::GetInstance().GetRandom(twoThirds + 1, i); //We want the upper half of the list to be gauranteed to both be larger and random.
			quickSource[j] = value;
			randomQuickSource[j] = value;
		}
		
		partialSortOutput << ",Quick Sort," << i << ",";
		std::clock_t quickTime = std::clock();
		quickSorter.Sort(quickSource, quickSource.size());
		partialSortOutput << std::setprecision(15) << (std::clock() - quickTime)/(double)CLOCKS_PER_SEC << ",";
		partialSortOutput << endl;

		partialSortOutput << ",Randomized Quick Sort," << i << ",";
		std::clock_t randomQuickTime = std::clock();
		randomQuickSorter.Sort(randomQuickSource, randomQuickSource.size());
		partialSortOutput << std::setprecision(15) << (std::clock() - randomQuickTime)/(double)CLOCKS_PER_SEC << ",";
		partialSortOutput << endl;
	}
	partialSortOutput.close();
}