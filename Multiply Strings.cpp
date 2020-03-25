/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
	string partMul(string num, int c)
	{
		int carry = 0, curret;
		string ret;
		for (int i = num.length()-1; i >= 0; i--)
		{
			curret = (num[i]-'0') * c + carry;

			carry = curret / 10;
			curret = curret % 10;

			ret.insert(ret.begin(), curret+'0');
		}
		if (carry) ret.insert(ret.begin(), carry+'0');
		return ret;
	}

	string add(string num1, string num2)
	{
		int carry = 0, curret;
		string ret;
		int len1 = num1.length(), len2 = num2.length();
		int i = len1-1, j = len2-1;
		for (; i >= 0 && j >= 0; i--, j--)
		{
			curret = (num1[i] - '0') + (num2[i] - '0') + carry;
			carry = curret / 10;
			curret = curret % 10;
			ret.insert(ret.begin(), curret+'0');
		}

		while (i >= 0)
		{
			curret = (num1[i] - '0') + carry;
			carry = curret / 10;
			curret = curret % 10;
			ret.insert(ret.begin(), curret+'0');
			i--;
		}
		while (j >= 0)
		{
			curret = (num2[j] - '0') + carry;
			carry = curret / 10;
			curret = curret % 10;
			ret.insert(ret.begin(), curret+'0');
			j--;
		}
		if (carry) ret.insert(ret.begin(), carry+'0');
		return ret;
	}

    string multiply(string num1, string num2)
    {
		string ret = "0", curret;
		for (int i = num2.length()-1; i >= 0; i--)
		{
			curret = partMul(num1, num2[i]-'0');
			for (int j = 0; j < num2.length()-1-i; j++)
				curret.push_back('0');
			ret = add(ret, curret);
		}
		return ret;
    }
};