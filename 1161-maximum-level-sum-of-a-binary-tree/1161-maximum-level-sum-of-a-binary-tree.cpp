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
    int maxLevelSum(TreeNode* root) {
        int sum=0, maxSum=INT_MIN, currLevel=1, ans=0;
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int i = q.size();
            sum = 0;
            while (i--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
                sum += curr->val;
            }
            if (sum > maxSum) {
                maxSum = sum;
                ans = currLevel;
            }
            currLevel++;
        }
        return ans;
    }
};