/*
Share
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class Solution {
public:
    void getNext(string needle, int next[])
    {
        int start = -1, end = 0;
        next[0] = -1;
        while (end < needle.length()-1)
        {
            if (start == -1 || needle[start] == needle[end])
            {
                start++; end++;
                next[end] = start;
            }
            else
                start = next[start];
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        int *next = new int[needle.length()];
        getNext(needle, next);

        int i = 0, j = 0;
        int needleLen = needle.length(); // we will compare this length with -1, change it from unsigned int to int
        while (i < haystack.length() && j < needleLen)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++; j++;
            }
            else
                j = next[j];
        }
        if (j == needle.length()) return i-j;
        else return -1;
    }
};