class Solution {
public:
//     no of unique ways to reach from i, j = no of ways to reach from i, j+1 + from i+1, j
    vector <vector <int>> dp;
    int M, N;
    int solve (int i, int j) {
        if (i==M || j==N)
            return 0;
        if (i==M-1 && j==N-1) {
            return dp[i][j]=1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = solve(i+1, j) + solve(i, j+1);
    }
    int uniquePaths(int m, int n) {
        vector <vector <int>> temp (m, vector <int>(n, -1));
        dp=temp;
        M=m, N=n;
        return solve(0, 0);
        
    }
};