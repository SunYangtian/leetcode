class Solution {
public:
	struct gridPoint
	{
		int value;
		vector<string> parenthesis;
	};
    vector<string> generateParenthesis(int n) {
        /* use a grid.
			start from the origin point. 
			each time move right or up
			when move right, generate (
			when move up, generate )
			make sure right pos >= up pos
        */
        // vector<vector<gridPoint>> grid;
        // for (int i = 0; i < n; i++)
        // 	grid[i].reserve(n);
        n = n+1; // add last, to avoid modify the below
        gridPoint grid[n][n];

        // initialize
        grid[0][0].value = 0;
        grid[0][0].parenthesis.push_back("");
        for (int i = 1; i < n; i++)
        {
        	grid[i][0].value = 1;
        	grid[i][0].parenthesis.push_back(grid[i-1][0].parenthesis[0] + "(");
        }
        // dynamic programming
        for (int i = 1; i < n; i++)
        {
        	for (int j = 1; j <= i; j++)
        	{
        		if (j == i)
        		{
        			grid[i][j].value = grid[i][j-1].value;
        			for (int k = 0; k < grid[i][j-1].parenthesis.size(); k++)
        				grid[i][j].parenthesis.push_back(grid[i][j-1].parenthesis[k] + ")");
        		}
        		else
        		{
        			grid[i][j].value = grid[i][j-1].value + grid[i-1][j].value;
        			for (int k = 0; k < grid[i][j-1].parenthesis.size(); k++)
        				grid[i][j].parenthesis.push_back(grid[i][j-1].parenthesis[k] + ")");
        			for (int k = 0; k < grid[i-1][j].parenthesis.size(); k++)
        				grid[i][j].parenthesis.push_back(grid[i-1][j].parenthesis[k] + "(");
        		}
        	}
        }
        return grid[n-1][n-1].parenthesis;
    }
};