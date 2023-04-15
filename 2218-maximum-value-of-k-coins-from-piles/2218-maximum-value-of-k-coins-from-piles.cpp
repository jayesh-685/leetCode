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
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp (size(piles), vector<int>(k+1, -1));
        return dfs(0, k, piles, dp);
    }
};