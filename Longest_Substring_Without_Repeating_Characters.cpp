// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 

// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t len = 0, point = 0;
        string sub = "";
        char c = s[point];
        size_t res = 0;

        while (point != s.length())
        {
            string tmp = "";
            tmp.push_back(c);
            size_t pos = sub.find_first_of(tmp);
            if (pos == string::npos)
            {
                len += 1;
            }
            else
            {
                len -= pos;
                sub.erase(0,pos+1);
            }
            sub.push_back(c);
            point += 1;
            c = s[point];

            if (res < len) res = len;
        }
    return (int)res;
    }
};

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(str) << endl;
    return 0;
}
