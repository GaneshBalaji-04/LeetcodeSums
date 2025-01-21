class Solution {
    void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& nums) {
        if (curr.size() == nums.size())
            result.push_back(curr);

        for (int i = 0; i < nums.size(); i++) {
            if (find(curr.begin(), curr.end(), nums[i]) == curr.end()) {
                curr.push_back(nums[i]);
                backtrack(result, curr, nums);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(result, curr, nums);
        return result;
    }
};

int init = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();