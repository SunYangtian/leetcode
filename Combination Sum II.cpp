/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
class Solution {
public:
	void sumKernel(vector<int>& candidates, int newtarget, vector<int>& curRet, vector<vector<int>>& ret, int start)
	{
		if (newtarget < 0) return;
		else if (newtarget == 0 && find(ret.begin(), ret.end(), curRet) == ret.end()) 
			{ret.push_back(curRet); return;}
		else
		{		
	        for (int i = start; i < candidates.size(); i++)
	        {

        		curRet.push_back(candidates[i]);
        		sumKernel(candidates, newtarget - candidates[i], curRet, ret, i+1);

        		curRet.pop_back();
        	}

		}

	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curRet;
        sort(candidates.begin(), candidates.end());

        sumKernel(candidates, target, curRet, ret, 0);
        return ret;
    }
};