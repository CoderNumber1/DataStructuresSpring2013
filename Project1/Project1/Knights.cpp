//----------------------------------------------------------------
//Author:		Karl Anthony James
//E-Mail:		kjames21@uco.edu
//Course:		CMSC 3613 - Data Structures and Algorithms
//CRN:			26119, Spring 2013
//Project:		PA1
//Due:			Febuary 20, 2013
//Account		gp034
//----------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include "Knights.h"

using namespace std;

//Function: Knights - Instantiate a knights configuration object.
//Parameter: size - The size used to create the chess board.
Knights::Knights(int size){
	this->boardSize = size;
	this->moveCount = 0;
	this->requiredMovesCount = size * size;

	for(int row = 0; row < this->boardSize; row++)
	{
		for(int col = 0; col < this->boardSize; col++)
		{
			this->knightsBoard[row][col] = -1;
		}
	}
}

//Function: IsSolved - If we've recorded enough successfull moves to fill the board
//		, then we've solved the knights tour.
bool Knights::IsSolved() const {
	return this->moveCount == this->requiredMovesCount;
}

//Function: Print - Print out the current state of the board.
void Knights::Print() const {
	for(int row = 0; row < this->boardSize; row ++) {
		for(int col = 0; col < this->boardSize; col ++) {
			cout << setw(4) << this->knightsBoard[row][col];
		}
		cout << endl;
	}
}

//Function: IsCellValid - Check that the row and column represent an actual cell on the knights board.
//Parameter: row - the row the cell is located at.
//Parameter: col - the column the cell is located at.
bool Knights::IsCellValid(int row, int col) const {
	return (row >= 0 && row < this->boardSize)
		&& (col >= 0 && col < this->boardSize);
}

//Function: IsCellVisited - Check if we've already moved the knight into this cell.
bool Knights::IsCellVisited(int row, int col) const {
	return this->knightsBoard[row][col] > -1;
}

//Function: VisitCell - Records that the knight has moved to the cell.
//Parameter: row - the row the cell is located at.
//Parameter: col - the column the cell is located at.
void Knights::VisitCell(int row, int col) {
	this->knightsBoard[row][col] = ++this->moveCount;
}

//Function: UnVisitCell - Removes the knights move to the indicated cell.
//Parameter: row - the row the cell is located at.
//Parameter: col - the column the cell is located at.
void Knights::UnVisitCell(int row, int col) {
	this->knightsBoard[row][col] = -1;
	this->moveCount--;
}