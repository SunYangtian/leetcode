class Solution {
public:
    int search(vector<int>& nums, int target) {
    	// find index of min value, which is the position of rotated
    	// two sorted part as a whole, binary search is still useful
     	int low = 0, high = nums.size()-1;
     	while (low < high)
     	{
     		int mid = (low + high) / 2;
     		if (nums[mid] < nums[high]) high = mid;
     		else low = mid+1;
     	}

     	// then use a new binary sort >>>>>>>>>>>> real mid
        // in this case, the condition is low <= high ,wihch is different from above
        // in this case, when find a value > target, high=mid-1, is different from above
     	int rot = low;
     	low = 0; high = nums.size()-1;
     	while (low <= high)
     	{
     		int mid = (low + high) / 2;
     		int realMid = (mid + rot) % nums.size();
     		if (nums[realMid] == target) return realMid;
     		else if (nums[realMid] > target) high = mid-1;
     		else low = mid+1;
     	}
     	return -1;
    }
};