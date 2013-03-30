//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA1
//Due:			Febuary 20, 2013
//Account		gp034
//----------------------------------------------------------------

const int MAX_BOARD = 30;
const int MIN_BOARD = 1;

class Knights{
public:
	Knights(int size);
	bool IsSolved() const;
	void Print() const;
	bool IsCellValid(int row, int col) const;
	bool IsCellVisited(int row, int col) const;
	void VisitCell(int row, int col);
	void UnVisitCell(int row, int col);
	int boardSize;
private:
	int moveCount;
	int requiredMovesCount;
	int knightsBoard[MAX_BOARD][MAX_BOARD];
};