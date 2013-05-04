//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA1
//Due:			March 30, 2013
//Account		gp034
//----------------------------------------------------------------

class RandomGen{
public:
	static RandomGen& GetInstance();
	int GetRandom(int min, int max);
private:
	RandomGen();
	RandomGen(RandomGen const&);
	void operator=(RandomGen const&);
};