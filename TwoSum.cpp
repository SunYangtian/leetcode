// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> MAP;
        // for (auto iter = nums.cbegin(); iter != nums.cend(); iter++)
        int length = nums.size();
        vector<int> res;
        map<int,int>::iterator it;
        for (int i = 0; i < length; i++)
        {
            MAP.insert(pair<int,int>(nums.at(i), i));
            int completion = target - nums.at(i);
            it = MAP.find(completion);
            if(it != MAP.end() && it->second != i) //ugly
            {
                res.push_back(it->second);
                res.push_back(i);
                return res;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int tmp;
    vector<int> nums;
    cout << "input array" << endl;
    char c = ' ';
    while (c != '\n')
    {
        cin >> tmp;
        nums.push_back(tmp);
        c = getchar();
    }

    cout << "input target" << endl;
    int target;
    cin >> target;

    Solution sol;
    vector<int> res = sol.twoSum(nums,target);
    for(auto iter = res.cbegin(); iter != res.cend(); iter++)
    {
        cout << (*iter) << endl;
    }
    
    return 0;
}
