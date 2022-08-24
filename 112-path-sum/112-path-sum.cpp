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
    bool hasPathSum(TreeNode* root, int ts, int cs=0) {
        if (!root) 
            return false;
                
        cs += root->val;

        if (!root->left && !root->right && cs==ts)
            return true;
        
        // cout << root->val << " " << cs << endl;
        
        return ((hasPathSum(root->left, ts, cs)) || hasPathSum(root->right, ts, cs));
    }
};