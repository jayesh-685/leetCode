class TrieNode {
    public:
    bool isWord;
    TrieNode* child [26];
    TrieNode () {
        isWord=false;
        for (int i=0; i<26; i++)
            child[i]=NULL;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode ();
        
        for (auto s: words)
            insert(s, root);
        
        vector<string> res;
        int n=board.size(), m=board[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                solve(board, i, j, n, m, "", res, root);
            }
        }
        
        return res;
    }
    
    void insert (string s, TrieNode* root) {
        int n=s.length();
        
        for (int i=0; i<n; i++) {
            int next = s[i]-'a';
            if (!root->child[next])
                root->child[next] = new TrieNode();
            root = root->child[next];
        }
        
        root->isWord = true;
    }
    
    void solve (vector<vector<char>>& board, int i, int j, int n, int m, string s, vector<string>& res, TrieNode* root) {
        
        if (i<0 || j<0 || i>=n || j>=m || board[i][j]=='*')
            return;
        
        char c = board[i][j];
        int next = c-'a';
        root = root->child[next];
        
        if (!root) return;
        
        s += c;
        // cout << s << endl;
        board[i][j] = '*';

        if (root->isWord) {
            res.push_back(s);
            root->isWord = false;
        }
        
        solve(board, i-1, j, n, m, s, res, root);
        solve(board, i, j+1, n, m, s, res, root);
        solve(board, i+1, j, n, m, s, res, root);
        solve(board, i, j-1, n, m, s, res, root);
        
        board[i][j] = c;
    }
};