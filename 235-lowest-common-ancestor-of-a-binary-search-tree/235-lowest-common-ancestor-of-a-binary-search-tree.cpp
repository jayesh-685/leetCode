/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val >= q->val)
            swap(p, q);
        while (true) {
            int rval = root->val;
            if (p->val<=rval && q->val>=rval)
                return root;
            else if (p->val<=rval && q->val<=rval)
                root = root->left;
            else
                root = root->right;
        }
    }
};