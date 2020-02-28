/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> curret;
        if (nums.size() >= 4) 
        {
        	for (int i = 0; i < nums.size()-3; i++)
        	{
        		// ignore save value situation
        		if (i == 0 || nums[i] != nums[i-1])
        		{
        			for (int j  = i+1; j < nums.size()-2; j++)
        			{
        				// ignore save value situation
        				if (j == i+1 || nums[j] != num[j-1])
        				{
        					int low = j+1, high = nums.size()-1;
        					while (low < high)
        					{
        						int sum = nums[i] + nums[j] + nums[low] + nums[high];
	        					if (sum < target) low++;
	        					else if (sum > target) high--;
	        					else
	        					{
	        						curret.clear();
	        						curret.push_back(i);
	        						curret.push_back(j);
	        						curret.push_back(low);
	        						curret.push_back(high);
	        						ret.push_back(curret);
	        						// compare with 3Sum cloest!!!
	        						// avoid same solution (duplicate quadruplets)
	        						while (low < high && nums[low] == nums[low+1]) low++;
	        						while (low < high && nums[high] == nums[high-1]) high--;
	        						low++; high--;
	        					}	
        					}
        				}
        			}
        		}
        	}
        }
        return ret;
    }
};