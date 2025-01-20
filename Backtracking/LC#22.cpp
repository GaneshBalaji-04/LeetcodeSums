class Solution {
    void backtrack(int open,int close, vector<string>& result,string& curr){
        if(open==0 && close==0){
            result.push_back(curr);
            return;
        }
        if(open!=0){
            curr.push_back('(');
            backtrack(open-1,close,result,curr);
            curr.pop_back();
        }
        if(close - open >= 1){
            curr.push_back(')');
            backtrack(open,close-1,result,curr);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backtrack(n,n,result,curr);
        return result;
    }
};
