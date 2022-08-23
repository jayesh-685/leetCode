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
    bool leftCheck (TreeNode* root, int x) {
        if (!root)
            return true;
        return root->val<x && leftCheck(root->left, x) && leftCheck(root->right, x);
    }
    
    bool rightCheck (TreeNode* root, int x) {
        if (!root)
            return true;
        return root->val>x && rightCheck(root->left, x) && rightCheck(root->right, x);
    }
    
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return leftCheck(root->left, root->val) && rightCheck(root->right, root->val) && isValidBST(root->left) && isValidBST(root->right);
    }
};