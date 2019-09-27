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

void generateForDemo() {
    grid[0][0]=2;grid[0][1]=3;grid[0][2]=0;
    grid[1][0]=1;grid[1][1]=4;grid[1][2]=5;
    grid[2][0]=7;grid[2][1]=8;grid[2][2]=6;
}

void findZeroPlace(int zeroPlace[2]) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!grid[i][j]) {
				zeroPlace[0] = i;
				zeroPlace[1] = j;
			}
		}
	}
}

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
				if (gridArrFlat[j] > gridArrFlat[i])
					++numOfReversePairs;
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

	if (rowInt < 0 || rowInt > 2 || col < 0 || col > 2) {
		return -1;
	}

	findZeroPlace(zeroPlace);

	if (rowInt == zeroPlace[0] && col == zeroPlace[1]) {
		return 0;
	}

	if (rowInt == zeroPlace[0] || col == zeroPlace[1]) {
		return 1;
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
	int rowInt = row - 65;
	int zeroPlace[2];
	int selectedVal = grid[rowInt][col];

	findZeroPlace(zeroPlace);

	int rowDiff = rowInt - zeroPlace[0];
	int colDiff = col - zeroPlace[1];

	if (rowDiff == 2 || rowDiff == -2) {
		int betweenVal = grid[1][col];
		grid[1][col] = 0;
		grid[zeroPlace[0]][zeroPlace[1]] = betweenVal;
		grid[1][col] = selectedVal;
		grid[rowInt][col] = 0;
	} else if (colDiff == 2 || colDiff == -2) {
		int betweenVal = grid[rowInt][1];
		grid[rowInt][1] = 0;
		grid[zeroPlace[0]][zeroPlace[1]] = betweenVal;
		grid[rowInt][1] = selectedVal;
		grid[rowInt][col] = 0;
	}	else {
		grid[rowInt][col] = 0;
		grid[zeroPlace[0]][zeroPlace[1]] = selectedVal;
	}
}

/*
  Task 4: Check whether the puzzle is solved.
 */
bool win() {
	// Complete this function by putting your code below
	// Use i%3 
	int correctCount = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 2 && j == 2 && !grid[i][j]) {
				++correctCount;
			} else {
				correctCount += (grid[i][j] == 3*i+j+1) ? 1 : 0;
			}
		}
	}

	return (correctCount == 9);
}

// Game loop.
int main() {
	srand(unsigned(time(nullptr))); // Initialize pseudo-random number generator.
	generate();
	// generateForDemo();

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
