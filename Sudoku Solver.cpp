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