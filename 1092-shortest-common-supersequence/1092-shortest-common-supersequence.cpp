class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(), m=str2.length();
        
        vector<vector<int>> dp (n+1, vector<int>(m+1));
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                dp[i][j] = str1[i-1]==str2[j-1] ? 1+dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int i=n, j=m;
        
        string s="";
        while (i>0 && j>0) {
            if (dp[i][j]>dp[i-1][j] && dp[i][j]>dp[i][j-1]) {
                s += str1[i-1];
                i--; j--;
            } else if (dp[i][j] == dp[i-1][j]) {
                i--;
            } else {
                j--;
            }
        }
        
        reverse(s.begin(), s.end());
        i = 0, j = 0;
        string res = "";
        string A=str1, B=str2;
        for (char c : s) {
            while (A[i] != c)
                res += A[i++];
            while (B[j] != c)
                res += B[j++];
            res += c, i++, j++;
        }
        return res + A.substr(i) + B.substr(j);
    }
};