class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int>(K+1)));
        
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<2; j++) {
                for (int k=1; k<=K; k++) {
                        if (j) {
                            dp[i][j][k] = max(dp[i+1][1][k], -prices[i]+dp[i+1][0][k]);
                        } else {
                            dp[i][j][k] = max(dp[i+1][0][k], prices[i]+dp[i+1][1][k-1]);
                        }
                }
            }
        }
        
        return dp[0][1][K];
    }
};