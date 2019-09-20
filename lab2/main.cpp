/*
 * main.cpp
 *
 *  Created on: 20 Sep 2019
 *      Author: keitaiwasaki
 */

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int grid[3][3];
const int MAX_WIDTH = 7;
const int ELEMENT_NUM = 9;

void display() {
	cout << "\n\n";
	cout << left;
	cout << "  | ";
        for(int i = 0; i < 3; i++)
         	cout << setw(MAX_WIDTH) << i;
	cout << endl;
        cout << "--+-------------------" << endl;
	for(int i = 0; i < 3; i++) {
		cout << (char)('A' + i) << " | ";
		for(int j = 0; j < 3; j++) {
			cout << setw(MAX_WIDTH) << grid[i][j];
		}
		cout << "\n  |\n";
	}
}

/*
  Task 1: Generate a puzzle
  - Shuffle the 8 numbers and the empty cell.
  - Make sure the generated puzzle has a solution by checking whether there exist a reverse pair.
 */
int myRandom (int i) { return std::rand()%i;}

void generate() {
	// Complete this function by putting your code below
	int gridArr[ELEMENT_NUM];
	int gridArrFlat[ELEMENT_NUM-1];
	bool isValidGrid = false;

	do {
		for (int i = 0; i < ELEMENT_NUM; ++i) {
			gridArr[i] = i;
		}

		random_shuffle(gridArr, gridArr + ELEMENT_NUM, myRandom);

		{
			int j = 0;
			for (int i = 0; i < ELEMENT_NUM; ++i) {
				if (gridArr[i] != 0) {
					gridArrFlat[j] = gridArr[i];
					++j;
				}
			}
		}

		int numOfReversePairs = 0;
		for (int i = 0; i < ELEMENT_NUM-1; ++i) {
			for (int j = i+1; j < ELEMENT_NUM-1; ++j) {
				if (gridArrFlat[j] > gridArrFlat[i]) {
					++numOfReversePairs;
				}
			}
		}

		isValidGrid = (numOfReversePairs%2 == 0);
	} while(!isValidGrid);

	for (int i = 0; i < ELEMENT_NUM; ++i) {
		if (i < 3) {
			grid[0][i] = gridArr[i];
		} else if (i < 6) {
			grid[1][i-3] = gridArr[i];
		} else {
			grid[2][i-6] = gridArr[i];
		}
	}
}

/*
  Task 2: Check whether the cell is valid to click
  - A cell is valid to click if and only if the empty cell has the same row or column as it.
  - You should also check whether the cell exists.

  - Inputs: row and col refer to the row number and column number of the click
  - Output:
     - Return 1 if the click is valid.
     - Return 0 if this cell exists but cannot be clicked.
     - Return -1 for any other error.
 */
int check(char row, int col) {
	// Complete this function by putting your code below
	int rowInt = row - 65;
	int zeroPlace[2];
	int selectedPlace[2] = {rowInt, col};
	int canMovePlace[4][2];

	if (rowInt < 0 || rowInt > 3 || col < 0 || col > 3) {
		return -1;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!grid[i][j]) {
				zeroPlace[0] = i;
				zeroPlace[1] = j;
			}
		}
	}

	canMovePlace[0][0] = zeroPlace[0];
	canMovePlace[0][1] = zeroPlace[1]-1;
	canMovePlace[1][0] = zeroPlace[0]-1;
	canMovePlace[1][1] = zeroPlace[1];
	canMovePlace[2][0] = zeroPlace[0]+1;
	canMovePlace[2][1] = zeroPlace[1];
	canMovePlace[3][0] = zeroPlace[0];
	canMovePlace[3][1] = zeroPlace[1]+1;

	for (int i = 0; i < 4; ++i) {
		if (canMovePlace[i][0] == selectedPlace[0] && canMovePlace[i][1] == selectedPlace[1]) {
			return 1;
		}
	}

	return 0;
}

/*
  Task 3: Move the cells according to the following rules
  - If the clicked cell is next to the empty cell, you just swap the two cells.
  - If there is another cell between these two cells (the clicked cell and the empty cell),
    you have to first move the middle cell and then the clicked cell.

  - Inputs: row and col refer to the row number and column number of the click
 */
void operate(char row, int col) {
	// Complete this function by putting your code below
	cout << "Operating" << endl;
}

/*
  Task 4: Check whether the puzzle is solved.
 */
bool win() {
	// Complete this function by putting your code below
}

// Game loop.
int main() {
	srand(unsigned(time(0))); // Initialize pseudo-random number generator.
	generate();

	while(!win()) {
		display();

		cout << "Which cell do you want to click?" << endl;

		char row;
		int col;
		cin >> row >> col;

		int ok = check(row, col);

		switch (ok) {
			case 0:  cout << "This cell can't be clicked!" << endl;
				 break;
			case 1:  operate(row, col);
				 break;
			case -1: cout << "Invalid input!" << endl;
				 break;
			default: break;
		}
	}

	display();
	cout << "Nice!" << endl;

	return 0;
}
