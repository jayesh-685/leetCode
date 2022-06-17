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
    // -1 -> camera required
    // 0 -> has camera
    // 1 -> covered
    /*
    if any one of your children required a camera then you increment the count and return 0
    if any one of your children has a camera then you are covered so you return 1
    if both of the children are covered then you ask your parent node for a camera so you return -1
    if the root node requires the camera then increment one more time
    */
    int count = 0;
    
    int solve (TreeNode* root) {
        if (root == NULL)
            return 1;
        
        int ln = solve(root->left);
        int rn = solve(root->right);
        
        if (ln==-1 || rn==-1) {
            count++;
            return 0;
        }
        
        if (ln==0 || rn==0) {
            return 1;
        }
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        int val = solve(root);
        if (val==-1)
            count++;
        return count;
    }
};