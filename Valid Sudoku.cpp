// how to judge if an element in a array?
// Hash !!!
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	unordered_set<string> CharSet;
    	for (int i = 0; i < board.size(); i++)
    	{
    		for (int j = 0; j < board[i].size(); j++)
    		{
    			char curChar = board[i][j];
    			if (curChar != '.')
    			{
	    			if (!CharSet.insert(curChar + string("inRow") + to_string(i)).second)
	    				return false;
	    			if (!CharSet.insert(curChar + string("inCol") + to_string(j)).second)
	    				return false;
	    			if (!CharSet.insert(curChar + string("inblk") + to_string(i/3) +"-"+ to_string(j/3)).second)
	    				return false;
    			}
    		}
    	}
    	return true;
    }
};