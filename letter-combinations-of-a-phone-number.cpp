/*
Share
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
class Solution {
public:
	unordered_map<char, string> PHONE {
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"}
	};
	vector<string> ret;
	void backTrack(string combination, string nextDigits)
	{
		if (nextDigits.length() == 0) ret.push_back(combination);
		else
		{
			char c = nextDigits.front();
			nextDigits.erase(nextDigits.begin());

			string letters = this->PHONE[c];
			for (int idx = 0; idx < letters.size(); idx++)
			{
				string newCombination = combination.push_back(letters[idx]);
				backTrack(newCombination, nextDigits);
			}
		}
	}
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() != 0)
        	backTrack(string(""), digits);
        return ret;
    }
};