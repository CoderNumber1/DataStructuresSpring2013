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
#include "Knights.h"

using namespace std;

//Function: Solve - Recursive function used to solve the knights tour problem.
bool Solve(Knights &configuration, int row, int col) {
	if(configuration.IsSolved()) {
		configuration.Print();
		return true;
	}
	else if(configuration.IsCellValid(row, col) && !configuration.IsCellVisited(row, col)) {
		configuration.VisitCell(row, col);

		bool success = Solve(configuration, row + 1, col - 2);
		if(!success) {
			success = Solve(configuration, row - 1, col - 2);
			if(!success) {
				success = Solve(configuration, row + 1, col + 2);
				if(!success) {
					success = Solve(configuration, row - 1, col + 2);
					if(!success) {
						success = Solve(configuration, row - 2, col + 1);
						if(!success) {
							success = Solve(configuration, row - 2, col - 1);
							if(!success) {
								success = Solve(configuration, row + 2, col + 1);
								if(!success) {
									success = Solve(configuration, row + 2, col - 1);
								}
							}
						}
					}
				}
			}
		}

		if(!success) configuration.UnVisitCell(row, col);
		else return true;
	}

	return false;
}

int main() {
	int boardSize;
	
	cout << "Enter the board size: " << flush;
	cin >> boardSize;

	if(boardSize < MIN_BOARD || boardSize > MAX_BOARD)
		cout << "The board size must be between " << MIN_BOARD << " and " << MAX_BOARD << endl;
	else {
		Knights configuration(boardSize);

		int startRow, startCol;

		cout << "Enter the starting row: " << flush;
		cin >> startRow;

		if(!configuration.IsCellValid(startRow, 0))
			cout << "The starting row must be between 0 and " << configuration.boardSize - 1 << endl;
		else {
			cout << "Enter the starting column: " << flush;
			cin >> startCol;

			if(!configuration.IsCellValid(startRow, startCol))
				cout << "The starting column must be between 0 and " << configuration.boardSize - 1 << endl;
			else {
				bool success = Solve(configuration, startRow, startCol);

				if(!success) {
					cout << "No solution found." << endl;
				}
			}
		}
	}
}