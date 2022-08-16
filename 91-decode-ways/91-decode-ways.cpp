class Solution {
public:
    vector <int> dp;
    int solve (string s, int i) {
        if (i==s.length())
            return 1;
        
        if (dp[i] != -1)
            return dp[i];
        int l1=0;
        if (s[i]!='0')
            l1 = solve(s, i+1);
        int l2=0;
        if (i<s.length()-1) {
            string temp = s.substr(i, 2);
            if (temp>="10" && temp<="26")
                l2 = solve(s, i+2);
        }
        
        return dp[i] = l1 + l2;
    }
    int numDecodings(string s) {
        vector <int> temp (s.length(), -1);
        dp = temp;
        return solve(s, 0);
    }
};