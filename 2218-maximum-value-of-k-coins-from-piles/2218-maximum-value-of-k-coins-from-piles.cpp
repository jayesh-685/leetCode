class Solution {
public:
    // can be done recursively with memoization you just have to figure out the recursion parameters
    // for each pile we have two choices, skip the pile or chose the coin
    
    
    int dfs (int i, int coins, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (i==size(piles)) return 0;
        
        if (dp[i][coins] != -1) return dp[i][coins];
        
        int ans = dfs(i+1, coins, piles, dp);  // skipping current pile
        
        int curr=0;
        for (int j=0; j<min(coins, (int)piles[i].size()); j++) {
            curr += piles[i][j];
            ans = max(ans, curr+dfs(i+1, coins-j-1, piles, dp));
        }
        
        return dp[i][coins]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int coins) {
        // vector<vector<int>> dp (size(piles), vector<int>(k+1, -1));
        // return dfs(0, k, piles, dp);
        
        int n=size(piles);
        vector<vector<int>> dp (n+1, vector<int>(coins+1));
        
        for (int i = 1; i <= piles.size(); i++) {
            dp[i][0] = 0;
        }
        
        for (int i=1; i<=n; i++) {
            for (int k=1; k<=coins; k++) {
                int curr=0;
                for (int j=0; j<min(k, (int)size(piles[i-1])); j++) {
                    curr += piles[i-1][j];
                    dp[i][k] = max(dp[i][k], curr+dp[i-1][k-j-1]);
                }
                dp[i][k] = max(dp[i][k], dp[i-1][k]);
            }
        }
        
        return dp[n][coins];
    }
};