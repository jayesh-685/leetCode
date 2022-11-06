class Solution {
public:
    int maxProfit(vector<int>& prices, int i=0, int buy=1) {
        
//         if (i==prices.size())
//             return 0;
//         int nothing, transaction;
        
//         if (buy) {
//             nothing = maxProfit(prices, i+1, 1);
//             transaction = -prices[i] + maxProfit(prices, i+1, 0);
//         } else {
//             nothing = maxProfit(prices, i+1, 0);
//             transaction = prices[i] + maxProfit(prices, i+1, 1);
//         }
        
//         return max(nothing, transaction);
        
        int n=prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2));
        
        dp[n][0] = dp[n][1] = 0;
        
        
        for (int i=n-1; i>=0; i--) {
            dp[i][0] = max(dp[i+1][0], prices[i]+dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1], -prices[i]+dp[i+1][0]);
        }
        
        return dp[0][1];
        
    }
};