//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA1
//Due:			March 30, 2013
//Account		gp034
//----------------------------------------------------------------

#include <time.h>
#include <stdlib.h>
#include "RandomGen.h"

RandomGen& RandomGen::GetInstance(){
	static RandomGen instance;
	return instance;
}

using namespace std;
RandomGen::RandomGen() { 
	srand(time(NULL));
}

int RandomGen::GetRandom(int min, int max){
   double x = rand()/static_cast<double>(RAND_MAX); 
   int result = min + static_cast<int>(x * (max - min));

   return result;
}
