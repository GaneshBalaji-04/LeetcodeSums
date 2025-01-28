class Solution {
public:
    int dp[1001][1001];
    int dfs(vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];
        if (dp[left][right] != -1)
            return dp[left][right];
        int pickLeft = nums[left] - dfs(nums, left + 1, right);
        int pickRight = nums[right] - dfs(nums, left, right - 1);
        dp[left][right] = max(pickLeft, pickRight);
        return dp[left][right];
    }

    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return dfs(nums, 0, nums.size() - 1) >= 0;
    }
};
