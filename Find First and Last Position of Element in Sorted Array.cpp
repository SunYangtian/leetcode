/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> res(-1,1);
        if (nums.size() == 0) return res;

        int low = 0, high = nums.size()-1, mid;
        int FLAG = 0;
        while (low <= high)
        {
        	mid = (low + high) / 2;
        	if (nums[mid] < target) low = mid + 1;
        	else if (nums[mid] > target) high = mid - 1;
        	else {FLAG = 1; break;}
        }

        if (FLAG)
        {
        	res.clear();
        	int left = mid, right = mid;
        	while (left > 0 && nums[left-1] == target) left--;
        	while (right < nums.size()-1 && nums[right+1] == target) right++;
        	res.push_back(right);
        	res.push_back(left);
        }
        else return res;
    }
};