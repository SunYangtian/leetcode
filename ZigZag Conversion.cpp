/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
*/

// visit by row
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
        	return s;
        string ret = "";
        // index of first row: k*(2*numRows-2)
        int k = 0;
        int index = k*(2*numRows-2);
        while ( index < s.length())
        {
        	ret.push_back(s[index]);
        	k += 1;
        	index = k*(2*numRows-2); 
        }
        // index from first to last: k*(2*numRows-2)+i, (k+1)*(2*numRows-2)-i;
        k = 0;
        int i = 1;
        while (i < numRows-1)
        {
        	// process each row
        	index = k*(2*numRows-2)+i;
        	while (index < s.length())
        	{    		
	        	if (index < s.length())
	        	{
	        		ret.push_back(s[index]);
	        	}

	        	index = (k+1)*(2*numRows-2)-i;
	        	if (index < s.length())
	        	{
	        		ret.push_back(s[index]);
	        	}
	        	else
	        		break;
	        	k += 1;
	        	index = k*(2*numRows-2)+i;
        	}
        	i += 1;
        	k = 0;
        }
        // the last row
        k = 0;
		index = k*(2*numRows-2) + (numRows-1);
        while ( index < s.length())
        {
        	ret.push_back(s[index]);
        	k += 1;
        	index = k*(2*numRows-2) + (numRows-1); 
        }

        return ret;
    }
};