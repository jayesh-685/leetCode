/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs (TreeNode* root, int ts, vector<int>& v) {
        if (!root)
            return;
        
        ts -= root->val;
        v.push_back(root->val);
        if (!ts && !root->left && !root->right) {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        
        dfs(root->left, ts, v); dfs(root->right, ts, v);
        v.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        dfs(root, targetSum, v);
        return ans;
    }
};