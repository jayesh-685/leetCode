class Solution {
public:
    // using string normalization
    // converting all occurences of first found character to a, all occurences of second found character to b, then c and so on...
    // Consider the words "mmnpoq" and "ppqqqz". We can convert these into - "aabcde" and "aabbbc". Since they are not equal, we can say both these words don't match.
// Similarly, the words "mnpqrr" and "xyzabb" can be converted into "abcdee" and "abcdee" respectively. Since they are equal, we say that these two words match.
    
    string normalize (string s) {
        unordered_map <char, char> m;
        char x='a';
        for (auto c: s) {
            if (!m.count(c))    m[c] = x++;
        }
        
        for (auto& c: s)
            c = m[c];
        
        return s;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        pattern = normalize(pattern);
        vector <string> ans;
        for (auto s: words) 
            if (normalize(s) == pattern)
                ans.push_back(s);
        
        return ans;
    }
};