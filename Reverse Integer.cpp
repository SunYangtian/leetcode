// INT_MAX 2147483647
// INT_MIN -2147483648
class Solution {
public:
    int reverse(int x) {
        int ret = 0, sign, pop;
        bool flag = true;
        sign = x>0?1:-1;

        // fetch the last digit
        while (x != 0)
        {
        	pop = x % 10;
        	x = x / 10;
        	// check if overflow
        	if (ret*sign > INT_MAX/10) flag = false;
	        else if (ret*sign == INT_MAX/10)
	        {
	        	if (sign > 0 && pop > 7) flag = false;
	        	else if (sign < 0 && pop > 8) flag = false;
	        }
	        if (flag) ret = ret*10 + pop;
	        else return 0;
        }
        return ret;
    }
};
