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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> ans;
        queue <TreeNode*> q;
        int level = 1;
        if (root == NULL)
            return ans;
        q.push(root);
        while (!q.empty()) {
            int i = q.size();
            vector <int> v;
            while (i--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
                v.push_back(curr->val);
            }
            if (level%2 == 0)
                reverse(v.begin(), v.end());
            ans.push_back(v);
            level++;
        }
        return ans;
    }
};