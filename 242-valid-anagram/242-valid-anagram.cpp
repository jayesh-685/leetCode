class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> arr (26, 0);
        for (auto c: s)
            arr[c-'a']++;
        
        for (auto c: t) {
            arr[c-'a']--;
            if (arr[c-'a']<0)
                return false;
        }
        
        for (int i=0; i<26; i++) {
            if (arr[i]!=0)
                return false;
        }
        
        return true;
    }
};