/*
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

Example 1:

Input: nums = [1]

Output: true

Explanation:

There is only one element. So the answer is true.

Example 2:

Input: nums = [2,1,4]

Output: true

Explanation:

There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

Example 3:

Input: nums = [4,3,1,6]

Output: false

Explanation:

nums[1] and nums[2] are both odd. So the answer is false.


*/

/*
February 1
*/

class Solution {
public:
    bool solve(vector<int>& nums, bool parity1, bool parity2) {
        if (nums.size() == 1)
            return true;
        if (parity1 == parity2)
            return false;
        if (nums.size() == 2 && parity1 != parity2)
            return true;
        vector<int> n(nums.begin() + 1, nums.end());
        return solve(n, n[0] % 2, n[1] % 2);
    }
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        return solve(nums, nums[0] % 2, nums[1] % 2);
    }
};
