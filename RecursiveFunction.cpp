////
// Author:       Your Name 
// Section:      A or S
// Assignment:   #
// Description:  Short description of what the program accomplishes  
// (at least a couple sentences – also you should say where the input
//  data comes from, what information is output, and where the output 
//  data is sent to (the screen or a file)  
////
#include <iostream>
#include <iomanip>
using namespace std;


// Global variables

unsigned long int moveNum = 1;
int board[8][8] = { };
//Function Protos
bool moveKnight(int row, int col, int moveNum);
void printBoard(int moveNum);

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
	if ((row >= 8) || (8 <= col) || (row < 0 || col < 0) || (board[row][col] != 0))
	{
		return false;
	}
	board[row][col] = moveNum;
	printBoard(moveNum);
	system("pause");

	if (moveNum == 64)
	{
		return true;
	} 
	cout << "Move 1 " << row - 2 << col + 1 << endl;
	if (moveKnight(row - 2, col + 1, moveNum + 1)) // Move '1' 
	{
		return true; 
	}
	cout << "Move 2 " << row + 2 << col - 1 << endl;
	if (moveKnight(row + 2, col - 1, moveNum + 1)) // Move '2' 
	{
		return true;
	}
	cout << "Move 3 " << row + 2 << col + 1 << endl;
	if (moveKnight(row + 2, col + 1, moveNum + 1)) // Move '3' 
	{
		return true;
	} 
	cout << "Move 4  " << row + 2 << col + 1 << endl;
	if (moveKnight(row + 2, col + 1, moveNum + 1)) // Move '4' 
	{
		return true; // this is an array + moves down | - moves up
	}
	board[row][col] = 0;



} 
void printBoard(int moveNum)
{
	for (auto& arr : board)
	{
		for (int ele : arr)
		{
			cout << setw(3) << ele;
		}
		cout << endl;
	}
	cout << moveNum;
}