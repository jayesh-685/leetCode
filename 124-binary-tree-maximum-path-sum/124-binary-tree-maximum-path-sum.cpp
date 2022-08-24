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
//     for each node we can either split the path from it or not
//     if we split the path answer is leftpath + root + rightpath and if don't split ans is root+left path or root+rightpath
//     we will use a global variale and update it with the value obtained when we split from curr node but return the value obtained by not splitting
    
    int ans;
    int solve (TreeNode* root) {
        if (!root)
            return 0;
        
//         can max path sum for left and right sub trees
        int ls=solve(root->left);
        int rs=solve(root->right);
//         no point in including them if they are negative
        ls = max(ls, 0);    
        rs = max(rs, 0);
        
        ans = max(ans, ls+root->val+rs);
        
        return root->val + max(ls, rs);
    }
    int maxPathSum(TreeNode* root) {
        ans = root->val;
        solve(root);
        return ans;
    }
};