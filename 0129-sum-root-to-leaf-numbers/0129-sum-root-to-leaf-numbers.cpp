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
    int sum;
    void solve (TreeNode* root, int csum) {
        csum += root->val;
        if (!root->left && !root->right) {
            sum += csum;
            return;
        }   
        
        if (root->left)     solve(root->left, csum*10);
        if (root->right)    solve(root->right, csum*10);
    }
    int sumNumbers(TreeNode* root) {
        sum=0;
        solve(root, 0);
        return sum;
    }
};