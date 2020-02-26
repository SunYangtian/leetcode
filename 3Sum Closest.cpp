/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
	int integerDiff(int a, int b)
	{
		if (a > b) return (a-b);
		else return (b-a);
	}

    int threeSumClosest(vector<int>& nums, int target) {
        int ret, curret, curdiff, diff = 999999;
        sort(nums.begin(), nums.end());
        // for (int i = 0; i < nums.size()-1; i++) cout << nums[i] << " ";
        // cout << endl;
        for (int i = 0; i < nums.size()-2; i++)
        {
          if (i == 0 || nums[i] != nums[i-1])
          {
                int low = i+1, high = nums.size()-1;
                while (low < high)
                {
                    curret = nums[i] + nums[low] + nums[high];
                    curdiff = integerDiff(target, curret);    			
                //cout << curret << ", " << curdiff << ", " << diff << endl;
                    if (curdiff < diff)	
                    {
                        ret = curret;
                        diff = curdiff;
                        // cout << curret << ", " << curdiff << ", " << diff << endl;
                    }
                    if (curret < target)  low++;
                    else if (curret > target) high--;
               else return curret;
                }
          }
        }
        return ret;
    }
};
