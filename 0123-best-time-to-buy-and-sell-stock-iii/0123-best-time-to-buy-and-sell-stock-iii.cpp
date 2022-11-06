class Solution {
public:
//     int maxProfit(vector<int>& prices, int i, int buy, int count, vector<vector<vector<int>>>& dp) {
//         if (i==prices.size() || count==0)
//             return 0;
        
//         if (dp[i][buy][count] != -1)
//             return dp[i][buy][count];
//         int nothing=0, transaction=0;
//         if (buy) {
//             nothing = maxProfit(prices, i+1, 1, count, dp);
//             transaction = -prices[i] + maxProfit(prices, i+1, 0, count, dp);
//         } else {
//             nothing = maxProfit(prices, i+1, 0, count, dp);
//             transaction = prices[i] + maxProfit(prices, i+1, 1, count-1, dp);
//         }
        
//         return dp[i][buy][count] = max(nothing, transaction);
//     }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int>(3)));
        
        // return maxProfit(prices, 0, 1, 2, dp);
        
        for (int i=0; i<3; i++) {
            dp[n][0][i] = 0;
            dp[n][1][i] = 0;
        }
        
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<3; k++) {
                    if (k==0)
                        dp[i][j][k]=0;
                    else {
                        if (j) {
                            dp[i][j][k] = max(dp[i+1][1][k], -prices[i]+dp[i+1][0][k]);
                        } else {
                            dp[i][j][k] = max(dp[i+1][0][k], prices[i]+dp[i+1][1][k-1]);
                        }
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};