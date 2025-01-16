/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void backtrack(TreeNode* root, vector<vector<int>>&ans, vector<int>&temp) {
        if(root==nullptr)
        return;
        temp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(temp);
        }
        else{
            backtrack(root->left,ans,temp);
            backtrack(root->right,ans,temp);
        }
        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(root,ans,temp);
        vector<string> result;
        for(int i=0;i<ans.size();i++){
            string s;
            for(int j=0;j<ans[i].size();j++){
                s = s + to_string(ans[i][j]) + "->";
            }
            s.pop_back();//These two lines are used to remove the last extra arrow mark, i.e. to remove '-' and '>'
            s.pop_back();
            result.push_back(s);
        }
        return result;
    }
};