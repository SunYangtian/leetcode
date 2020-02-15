/*
Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

//can be solved by suffix tree?

class Solution {
    public: string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        int* range = new int[2];
        range[0] = 0; range[1] = -1;
        // char* str = s.data();
        for (int i = 0; i < s.length(); i++) {
        	// find the symmetric character for each char, range keeps the longest
            i = findLongest(s, i, range);
        }
        return s.substr(range[0], range[1]-range[0]+1);
    }
    
    public: int findLongest(string str, int low, int* range) {
        int high = low;
        while (high < str.length() - 1 && str[high + 1] == str[low]) {
            high++;
        }

        int ans = high;

        while (low > 0 && high < str.length() - 1 && str[low - 1] == str[high + 1]) {
            low--;
            high++;
        }

        if (high - low > range[1] - range[0]) {
            range[0] = low;
            range[1] = high;
        }
        return ans;
    }
};