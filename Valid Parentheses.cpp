/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/
class Solution {
public:
    unordered_map<char, char> parentheseMap = 
    {
    	{'(',')'},
    	{'[', ']'},
    	{'{', '}'}
    };
    unordered_map<char, char>::iterator got;
    bool isValid(string s) {
        stack<char> S;
        // S.push('#'); // avoid empty stack
        for (int i  = 0; i < s.length(); i++)
        {
        	got = parentheseMap.find(s[i]);
        	if (got != parentheseMap.end())
        		S.push(s[i]); // open braket
        	else //close braket
        	{
        		if (!S.empty() && parentheseMap[S.top()] == s[i])
        			S.pop();
        		else
        			return false;
        	}
        }
        if (!S.empty()) return false;
        else return true;
    }
};