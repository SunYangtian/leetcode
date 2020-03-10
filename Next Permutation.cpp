/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	// iterate from right to left
    	int length = nums.size();
    	int idx = length-1;
    	while (idx > 0)
    	{
    		if (nums[idx] <= nums[idx-1]) idx--;
    		else break;
    	}
    	if (idx == 0)
    		reverse(nums.begin(), nums.end());
    	else
    	{
	    	int pivot = idx - 1;
	    	// find the pos just larger than nums[idx]
	    	while (idx < length)
	    	{
	    		if (nums[idx] > nums[pivot]) idx++;
	    		else break;
	    	}
	    	idx -= 1;
	    	// swap
	    	iter_swap(nums.begin()+pivot, nums.begin()+idx);
	    	//reverse
	    	reverse(nums.begin()+pivot+1, nums.end());
    	}
    }
};