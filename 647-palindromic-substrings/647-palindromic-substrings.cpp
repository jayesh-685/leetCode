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
    vector <vector <int>> dp;
    
    bool isPalindrome (int i, int j) {
        if (i>=j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (str[i]==str[j] && isPalindrome(i+1, j-1))
            return dp[i][j]=true;
        return dp[i][j]=false;
    }
    int countSubstrings(string s) {
        int ans=0;
        str=s;
        vector <vector <int>> temp (s.length()+1, vector<int>(s.length()+1, -1));
        dp = temp;
        for (int i=1; i<=s.length(); i++) {
            for (int j=0; j<i; j++) {
                if (isPalindrome(j, i-1))
                    ans++;
            }
        }
        
        return ans;
    }
};