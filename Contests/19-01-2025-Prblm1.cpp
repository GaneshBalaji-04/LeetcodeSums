/*
Q1. Sum of Variable Length Subarrays

You are given an integer array nums of size n. For each index i where 0 <= i < n, define a 
subarray
 nums[start ... i] where start = max(0, i - nums[i]).

Return the total sum of all elements from the subarray defined for each index in the array.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int start = max(0,i-nums[i]);
            ans = ans + accumulate(nums.begin()+start, nums.begin()+i+1, 0);
        }
        return ans;
    }
};