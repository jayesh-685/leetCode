class WordDictionary {
public:
    
    class tNode {
        public:
        
        tNode* child[26];
        bool isWord;
        tNode () {
            for (int i=0; i<26; i++)
                child[i] = NULL;
            isWord = false;
        }
    };
    
    WordDictionary() {
        root = new tNode();
    }
    
    void addWord(string word) {
        tNode* itr = root;
        for (int i=0; i<word.length(); i++) {
            int curr = word[i]-'a';
            if (!itr->child[curr])
                itr->child[curr] = new tNode();
            
            itr = itr->child[curr];
        }
        
        itr->isWord = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
    
private:
    tNode* root;
    bool search (string word, int k, tNode* head) {
        if (k==word.length())
            return head->isWord;
        
        if (word[k]=='.') {
            for (int i=0; i<26; i++) {
                if (head->child[i] && search(word, k+1, head->child[i]))
                    return true;
            }
        } else {
            int curr = word[k]-'a';
            return head->child[curr] && search(word, k+1, head->child[curr]);
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */