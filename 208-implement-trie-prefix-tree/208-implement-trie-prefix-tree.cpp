class Trie {
public:
    struct tNode {
        bool isWord;
        tNode* child[26];
        tNode () {
            isWord=false;
            for (int i=0; i<26; i++)
                child[i] = NULL;
        }
    };
    
    struct tNode* a;
    Trie() {
        a = new tNode();
    }
    
    void insert(string word) {
        tNode* itr = a;
        
        for (int i=0; i<word.length(); i++) {
            int curr=word[i]-'a';
            if (!itr->child[curr]) {
                itr->child[curr] = new tNode();
            }
            itr = itr->child[curr];
        }
        
        itr->isWord = true;
    }
    
    bool search(string word) {
        tNode* itr = a;
        for (int i=0; i<word.length(); i++) {
            int curr = word[i]-'a';
            if (!itr->child[curr])
                return false;
            itr = itr->child[curr];
        }
        
        return itr->isWord;
    }
    
    bool startsWith(string word) {
        tNode* itr = a;
        for (int i=0; i<word.length(); i++) {
            int curr = word[i]-'a';
            if (!itr->child[curr])
                return false;
            itr = itr->child[curr];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */