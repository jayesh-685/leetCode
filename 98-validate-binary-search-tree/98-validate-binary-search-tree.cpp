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
//     INT_MIN INT_MAX won't work
    
    bool validBST (TreeNode* root, long long min, long long max) {
        if (!root)
            return true;
        
        int val = root->val;
        return val>min && val<max && validBST(root->left, min, val) && validBST(root->right, val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return validBST(root, LONG_MIN, LONG_MAX);
    }
};