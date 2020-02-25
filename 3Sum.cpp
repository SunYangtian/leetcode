class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> ret;
    	vector<int> retElem;
        if (nums.size() < 3) return ret;
        sort(nums.begin(), nums.end()); // sort can only work with size > 2
    	for (int i = 0; i < nums.size()-2; i++)
    	{
    		int low = i+1, high = nums.size()-1;
    		int curres;
    		// if start or no same value, loop
    		if (i == 0 || nums[i] != nums[i-1])
    		{
	    		while (low < high)
	    		{
	    			curres = nums[i] + nums[low] + nums[high];
	    			if (curres < 0) low++;
	    			else if (curres > 0) high--;
	    			else
	    			{
	    				retElem.clear();
	    				retElem.push_back(nums[i]);
	    				retElem.push_back(nums[low]);
	    				retElem.push_back(nums[high]);
	    				ret.push_back(retElem);

	    				// ignore the same value, attention: low < hith to avoid access overflow
	    				while (low < high && nums[high] == nums[high-1]) high--;
	    				while (low < high && nums[low] == nums[low+1]) low++;

	    				// check next paired data
	    				high--; low++;
	    			}
	    		}
	    	}
    	}
    	return ret;
    }
};