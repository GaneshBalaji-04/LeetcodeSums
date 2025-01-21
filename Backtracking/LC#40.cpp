class Solution {
    void backtrack(int start, vector<vector<int>>& result, vector<int>& curr,
                   vector<int>& nums, int target) {
        if (target == 0) {
            if (find(result.begin(), result.end(), curr) == result.end())
                result.push_back(curr);
            return;
        }
        if (target < 0)
            return;

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            /* This if condition is very much important to avoid duplicate presence of the elements. There are test cases such as such as [1,2,2,2,5] by which [1,2,2] can be added but another 2 is not needed. In the test case [1,1,....1(100 times)], first 30 satisfies the target. Next ones are not needed and so, no need to be checked.*/
            curr.push_back(nums[i]);
            backtrack(i + 1, result, curr, nums, target - nums[i]);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(0, result, curr, candidates, target);
        return result;
    }
};