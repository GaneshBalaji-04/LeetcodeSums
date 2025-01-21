class Solution {
    int k_ori;
    void backtrack(int start,int n,vector<vector<int>> &result, vector<int> &curr,int k){
        if(k==k_ori){
            result.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            backtrack(i+1,n,result,curr,k+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        k_ori = k;
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(1,n,result,curr,0);
        return result;
    }
};