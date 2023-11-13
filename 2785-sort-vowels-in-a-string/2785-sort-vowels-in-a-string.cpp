class Solution {
public:
    bool isVowel (char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string sortVowels(string s) {
        vector<char> v;
        for (int i=0; i<s.length(); i++) {
            if(isVowel(s[i])){
                v.push_back(s[i]);
            }
        }
        
        sort(begin(v), end(v));
        
        int j=0;
        for (int i=0; i<s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = v[j];
                j++;
            }
        }
        
        return s;
    }
};