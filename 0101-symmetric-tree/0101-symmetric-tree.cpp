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
    
    bool areMirror (TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) {
            if (!root1 && !root2)
                return true;
            return false;
        }
    
        return (root1->val==root2->val) && areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
//         for two trees to be symmetric, their root nodes' values must be equal, root1->left & root2->right should be mirror images of each other and root1->right & root2->left should be mirror images of each other
        return areMirror(root->left, root->right);
    }
};