class Solution {
public:
    bool isPalindrome (string s) {
        for (int i=0; i<s.length()/2; i++) {
            if (s[i] != s[s.length()-i-1])
                return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans=0;
        for (int i=1; i<=s.length(); i++) {
            for (int j=0; j<i; j++) {
                if (isPalindrome(s.substr(j, i-j)))
                    ans++;
            }
        }
        
        return ans;
    }
};