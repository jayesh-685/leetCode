class Solution {
public:
    // bool isPalindrome (string s) {
    //     for (int i=0; i<s.length()/2; i++) {
    //         if (s[i] != s[s.length()-i-1])
    //             return false;
    //     }
    //     return true;
    // }
    
    string str;
    
    bool isPalindrome (int i, int j) {
        if (i>=j)
            return true;
        if (str[i]==str[j] && isPalindrome(i+1, j-1))
            return true;
        return false;
    }
    int countSubstrings(string s) {
        int ans=0;
        str=s;
        for (int i=1; i<=s.length(); i++) {
            for (int j=0; j<i; j++) {
                if (isPalindrome(j, i-1))
                    ans++;
            }
        }
        
        return ans;
    }
};