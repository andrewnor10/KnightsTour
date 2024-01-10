////
// Author:       Andrew Norton
// Section:      CS 132
// Assignment:   Knights Tour
// Description:  Have a theoretical chess knight visit every spot
// on the output 
//  data is sent to console
////
#include <iostream>
#include <iomanip>
using namespace std;


// Global variables

int moveNum = 1;
unsigned long int attempts = 1;
int board[8][8] = { };
//Function Protos
bool moveKnight(int row, int col, int moveNum);
void printBoard(int attempts);

int main()
{ 
	int row = 0, col = 0;
	if (moveKnight(row, col, moveNum))
	{
		printBoard(moveNum);
	}
	else
	{
		cout << "Error";
	}

	return 0;
}

bool moveKnight(int row, int col, int moveNum)
{

	if ((row >= 8) || (col >= 8) || row < 0 || col < 0 || (board[row][col] != 0))
	{
		// cout << moveNum << " return false\n\n";

		return false;
	}
	if (moveNum == 39)
	{
		cout << "39";
	}
	// cout << "Set board to " << moveNum << endl;
	board[row][col] = moveNum;
	// printBoard(attempts);

	attempts++;

	if (moveNum == 64)
	{
		cout << "Reached 64 \n";
		return true;
	} 
	// cout << "Move 1 " << row - 2 << col + 1 << endl;
	if (moveKnight(row - 2, col + 1, moveNum + 1)) // Move '1' 
	{
		return true; 
	}
	// cout << "Move 2 " << row - 1 << col + 2 << endl;
	if (moveKnight(row - 1, col + 2, moveNum + 1)) // Move '2' 
	{
		return true;
	}
	// cout << "Move 3 " << row + 1 << col + 2 << endl;
	if (moveKnight(row + 1, col + 2, moveNum + 1)) // Move '3' 
	{
		return true;
	} 
	// cout << "Move 4  " << row - 2 << col + 1 << endl;
	if (moveKnight(row + 2, col + 1, moveNum + 1)) // Move '4' 
	{
		return true; // this is an array + moves down | - moves up
	}
	// cout << "Move 5 " << row - 1 << col + 2 << endl;
	if (moveKnight(row + 2, col - 1, moveNum + 1)) // Move '5' 
	{
		return true;
	}
	// cout << "Move 6 " << row + 1 << col - 2 << endl;
	if (moveKnight(row + 1, col - 2, moveNum + 1)) // Move '6' 
	{
		return true;
	}
	// cout << "Move 7 " << row - 1 << col - 2 << endl;
	if (moveKnight(row - 1, col - 2, moveNum + 1)) // Move '7' 
	{
		return true;
	}
	// cout << "Move 8 " << row - 2 << col - 1 << endl;
	if (moveKnight(row - 2, col - 1, moveNum + 1)) // Move '8' 
	{
		return true;
	} 

	board[row][col] = 0;
	// printBoard(attempts);
	return false;

} 
void printBoard(int attempts)
{
	for (auto& arr : board)
	{
		for (int ele : arr)
		{
			cout << setw(3) << ele;
		}
		cout << endl;
	}
	cout << "Attempt: " << attempts << endl;
}
/*Result from 0,0

1 38 55 34  3 36 19 22
 54 47  2 37 20 23  4 17
 39 56 33 46 35 18 21 10
 48 53 40 57 24 11 16  5
 59 32 45 52 41 26  9 12
 44 49 58 25 62 15  6 27
 31 60 51 42 29  8 13 64
 50 43 30 61 14 63 28  7
Attempt: 1
*/