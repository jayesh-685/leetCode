class WordDictionary {
public:
    struct node {
        node* child[26];
        bool isWord;
        node() {
            isWord = false;
            for (int i=0; i<26; i++)    child[i]=NULL;
        }
    };
    
    node* root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        int n=word.length();
        struct node* ptr = root;
        for (int i=0; i<n; i++) {
            int c = word[i]-'a';
            if (ptr->child[c] == NULL) {
                ptr->child[c] = new node();
            }
            
            ptr = ptr->child[c];
        }
        
        ptr->isWord = true;
    }
    
    bool search(string word) {
        return search2(0, word, root);
    }
    
    bool search2 (int i, string word, struct node* ptr) {
        if (i==word.length())   return ptr->isWord;
        if (word[i] == '.') {
            for (int j=0; j<26; j++) {
                if (ptr->child[j] && search2(i+1, word, ptr->child[j])) 
                    return true;
            }
            return false;
        } else {
            int idx=word[i]-'a';
            return (ptr->child[idx] && search2(i+1, word, ptr->child[idx]));
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */