class Solution {
public:
    // check other submissions also
    //     using gap strategy 
    // string is a palindrome if first and last character are same and the remaining string is  also a palindrome
    string longestPalindrome(string s) {
        int n = s.length();
        int dp [n][n];
        int start=0, end=0;

        for (int g=0; g<n; g++) {
            for (int i=0, j=g; j<n; i++,j++) {
                if (g==0) {
                    dp[i][j] = 1;
                } else if (g==1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {
                    if ((s[i] == s[j]) && (dp[i+1][j-1])) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }
                }
                if (dp[i][j] && (j-i>end-start)) {
                    start = i; end = j;
                }
            }
        }
        return n==0?"":s.substr(start, end-start+1);
    }
};