/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

//INT_MAX
//INT_MIN
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        int res = 0;
        int sign = 1;

        long dividendD = (long) dividend;
        long divisorD = (long) divisor;

        if (dividendD < 0) {dividendD = -dividendD; sign = -sign;}
        if (divisorD < 0) {divisorD = -divisorD; sign = -sign;}
        
        while (dividendD >= divisorD)
        {
            long tmpDivisor = divisorD;
            int shift = 0;
            while (dividendD > (tmpDivisor<<1))
            {
                tmpDivisor = tmpDivisor << 1;
                shift += 1;
            }
            res += (1 << shift);
            dividendD -= tmpDivisor;
        }

        if (sign > 0) return res;
        else return -res;
    }
};