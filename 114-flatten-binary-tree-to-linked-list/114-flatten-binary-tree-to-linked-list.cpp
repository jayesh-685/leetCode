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
//     write a recursive function such that it flattens the tree and returns the tail of the linked list. using it flatten the left sub tree then the right sub tree, insert the left ll between the root and the right ll, and return tail of the final ll.
    TreeNode* dfs (TreeNode* root) {
        if (!root)
            return NULL;
//         flattening the right and left sub trees
        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);
        
//         we only need to insert left ll between root and right ll if it exists
        if (root->left) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        
//         tail of final ll depends on if right sub tree exists, left tree exists or both don't exist
        if (rightTail)
            return rightTail;
        if (leftTail)
            return leftTail;
        return root;
        
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};