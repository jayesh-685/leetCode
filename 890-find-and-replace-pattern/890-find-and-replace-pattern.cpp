class Solution {
public:
//     use 2 maps or 1 map and 1 array
    bool match (string s, string pattern) {
        unordered_map <char, char> m1;
        unordered_map <char, char> m2;
        for (int i=0; i<s.length(); i++) {
            char c=s[i], p=pattern[i];
            if (m1.find(c) == m1.end()) {
                if (m2.find(p) != m2.end())
                    return false;
                m1[c] = p; m2[p] = c;
            } else {
                if (m1[c]!=p)
                    return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector <string> ans;
        for (auto s: words)
            if (match(s, pattern))
                ans.push_back(s);
                
        return ans;
    }
};