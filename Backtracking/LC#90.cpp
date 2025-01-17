class Solution {
public:
    void backtrack(int start, vector<vector<int>>& result, vector<int>& curr,
                   vector<int>& nums) {
        if (find(result.begin(), result.end(), curr) == result.end())
            result.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, result, curr, nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        backtrack(0, result, curr, nums);
        return result;
    }
};
