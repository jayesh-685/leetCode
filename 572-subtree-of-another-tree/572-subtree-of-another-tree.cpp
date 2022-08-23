class Solution {
public:
    void ser(TreeNode *root, string& s) {
        if (!root) {
            s += '$';
            return;
        }
        
        s += '&' + to_string(root->val) + '&';
        ser(root->left, s);
        ser(root->right, s);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string s1;
        string s2;
        ser(s, s1);
        ser(t, s2);
        
        return s1.find(s2) != std::string::npos;
    }
};