/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
class Solution {
public:
	void sumKernel(vector<int>& candidates, int newtarget, vector<int>& curRet, vector<vector<int>>& ret, int start)
	{
		if (newtarget < 0) return;
		else if (newtarget == 0) {ret.push_back(curRet); return;}
		else
		{		
	        for (int i = start; i < candidates.size(); i++)
	        {

        		curRet.push_back(candidates[i]);
        		sumKernel(candidates, newtarget - candidates[i], curRet, ret, i);

        		curRet.pop_back();
        	}

		}

	}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curRet;
        sort(candidates.begin(), candidates.end());

        sumKernel(candidates, target, curRet, ret, 0);
        return ret;
    }
};