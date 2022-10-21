class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > t.length())
            return false;
        
        int p1=0, p2=0;
        for (; p1<t.length(); p1++) {
            if (p2==s.length())
                return true;
            if (t[p1] == s[p2])
                p2++;
        }
        
        return p2==s.length();
    }
};