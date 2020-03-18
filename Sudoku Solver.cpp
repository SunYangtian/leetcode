/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

class Solution {
public:
	bool isValid(vector<vector<char>>& board, int row, int col, char c)
	{
		int SIZE = board.size();
		int sqSIZE = sqrt(SIZE);
		for (int i = 0; i < SIZE; i++)
		{
			if (board[row][i] == c) return false;
			if (board[i][col] == c) return false;
			if (board[sqSIZE*(row/sqSIZE)+i/sqSIZE][sqSIZE*(col/sqSIZE)+i%sqSIZE] == c) return false;
		}
		return true;
	}
	bool solveKernel(vector<vector<char>>& board, int depth)
	{
    	int SIZE = board.size();
        depth += 1;
        // cout << "depth: " << depth << endl;
    	for (int i = 0; i < SIZE; i++)
    	{
    		for (int j = 0; j < SIZE; j++)
    		{
    			if (board[i][j] == '.')
    			{
    				for (char c = '1'; c <= '9'; c++)
    				{
    					if (isValid(board, i, j, c))
                        {
    						board[i][j] = c;
        					if (solveKernel(board, depth)) return true;
                        }
    				}
                    //cout << i << ", " << j << endl;
                    board[i][j] = '.'; // back track
                    return false;
    			}
    		}
    	}
        return true; 
	}
    void solveSudoku(vector<vector<char>>& board) {
        int depth = 0;
    	solveKernel(board, depth);
    }
};