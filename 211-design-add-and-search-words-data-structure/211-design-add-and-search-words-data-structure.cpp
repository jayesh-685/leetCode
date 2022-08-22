struct TrieNode{
    bool isKey;
    TrieNode* next[26];
    TrieNode():isKey(false){
        memset(next, NULL, sizeof(next));
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(auto c: word){
            if(!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isKey = true;
    }
    
    bool search(string word) {
        return helper(word, root);
    }

private:
    TrieNode* root;
    
    bool helper(string word, TrieNode* node){
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            if(c != '.'){
                if(!node->next[c - 'a']) return false;
                node = node->next[c - 'a'];
            }
            else{
                for (int j=0; j<26; j++) {
                    if (node->next[j] && helper(word.substr(i+1), node->next[j]))
                        return true;
                }
                return false;
            }
        }
        return node->isKey;
    }
};