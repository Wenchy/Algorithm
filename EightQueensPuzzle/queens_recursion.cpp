/**
 * 八皇后问题, recursion solver
 * @author Charles Wenchy <wenchy.zwz@gmail.com>
 * @version 1.0.0
 * @copyright Wenzhou Zhu
 * @license GPL3.0
 * @since 2015-4-9
 */
#include <iostream>
#include <cmath>
using namespace std;
#define NQUEEN 8 // EightQueensPuzzle.
int solutionCount = 0; // total results
int queens[NQUEEN + 1]; // NQUEEN+1 elements for easy process, default initialized to integer 0

bool judge(int row, int col){
	// Note: just compare before colum "col"
	for (int i = 1; i < col; i++)
	{
		int qrow = queens[i];
		int qcol = i;
		if (qrow == row || qcol == col || abs(qrow - row)  == abs(qcol - col))
		{
			return false;
		}
		
	}
	return true;
}
void print_queens()
{
	cout << "solution: " << solutionCount << endl;
	for (int i = 1; i <= NQUEEN; i++)
	{
		for (int j = 1; j <= NQUEEN; j++)
		{
			if (queens[j] == i)
			{
				cout << "#"; // "*" represents one Queen
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
	cout << endl;
}
void backtrack(int col){
	if (col > NQUEEN){
		solutionCount++; // Got a result, add one to solutionCount 
		print_queens(); //print the chessboard state of this puzzle's result
		return;
	}
	for (int i = 1; i <= NQUEEN; i++)
	{
		if (judge(i, col))
		{
			queens[col] = i;
			backtrack(col + 1);
		}
	}
}
int main(int argc, char* argv[])
{
	backtrack(1);
	cout << "Total Solution: " << solutionCount << endl;
	return 0;
