/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

class Solution {
public:
    bool isPalindrome(int x) {
    	if (x < 0 || (x % 10 == 0 && x != 0)) return false; //using half method, *0 must be processed as edge example 
        int halfX = x, halfRevX = 0;
        int popInt;
        // if x is palindrome, there must exits a momoent when halfX == halfRevX
        while (halfRevX < halfX)
        {
        	popInt = halfX % 10;
        	halfX /= 10;
        	halfRevX = halfRevX*10 + popInt;
        }
        if (halfX == halfRevX || halfX == halfRevX/10) return true; // odd/even respectively
        else return false;
    }
};