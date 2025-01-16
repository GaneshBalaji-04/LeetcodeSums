//My thought process
class Solution {
public:
    void backtrack(int start, vector<int> &nums,vector<int> &curr,vector<vector<int>> &result){
        result.push_back(curr);
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr,result);
            curr.pop_back();
        }
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res; 
        vector<int> curr;
        int result=0;
        backtrack(0,nums,curr,res);
        for(int i=0;i<res.size();i++){
            int xor_value=0;
            for(int j=0;j<res[i].size();j++){
                xor_value = xor_value ^ res[i][j];
            }
            result+=xor_value;
        }
        return result;
    }
};

//optimized approach
class Solution {
public:
    void backtrack(int start, vector<int>&nums,int currXOR, int &result){
        result+=currXOR;
        for(int i=start;i<nums.size();i++){
            backtrack(i+1,nums,currXOR ^ nums[i], result);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int result=0;
        backtrack(0,nums,0,result);
        return result;
    }
};