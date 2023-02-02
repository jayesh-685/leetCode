class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map <char, int> mp;
        for (int i=0; i<size(order); i++) {
            mp[order[i]] = i;
        }
        
        int n=size(words);
        
        for (int i=0; i<n-1; i++) {
            int j;
            for (j=0; j<min(size(words[i]), size(words[i+1])); j++) {
                char c1=words[i][j], c2=words[i+1][j];
                if (c1 != c2) {
                    if (mp[c1] > mp[c2]) return false;
                    else                 break;
                }
            }
            
            if (size(words[i]) > size(words[i+1]) && j==size(words[i+1]))  return false;
        }
        
        return true;
    }
};