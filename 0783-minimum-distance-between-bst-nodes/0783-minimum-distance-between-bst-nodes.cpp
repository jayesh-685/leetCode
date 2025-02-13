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
    TreeNode* prev;
    void solve (TreeNode* root, int& ans) {
        if (!root)  return;
        
        solve(root->left, ans);
        
        if (prev) {
            ans = min(ans, root->val-prev->val);
        }
        prev=root;
        
        solve(root->right, ans);
    }
    int minDiffInBST(TreeNode* root) {
        prev=NULL;
        int ans=INT_MAX;
        solve(root, ans);
        return ans;
    }
};