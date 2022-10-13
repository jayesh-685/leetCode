class Solution {
public:
    int mod = 1e9 + 7;
    int solve (vector<vector<int>>& grid, int k, int i, int j, int s, vector<vector<vector<int>>>& dp) {
        
        if (i<0 || j<0 || i==grid.size() || j==grid[0].size())
            return 0;
        
        if (i==grid.size()-1 && j==grid[0].size()-1)
            return (s+grid[i][j])%k == 0;
        
        if (dp[i][j][s]!=-1)
            return dp[i][j][s];
        
        return dp[i][j][s]=(solve(grid, k, i+1, j, (s+grid[i][j])%k, dp) + solve(grid, k, i, j+1, (s+grid[i][j])%k, dp))%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(k, -1))); 
        return solve(grid, k, 0, 0, 0, dp);
    }
};