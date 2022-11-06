class Solution {
public:
    int maxProfit(vector<int>& prices, int i, int buy, int count, vector<vector<vector<int>>>& dp) {
        if (i==prices.size() || count==0)
            return 0;
        
        if (dp[i][buy][count] != -1)
            return dp[i][buy][count];
        int nothing=0, transaction=0;
        if (buy) {
            nothing = maxProfit(prices, i+1, 1, count, dp);
            transaction = -prices[i] + maxProfit(prices, i+1, 0, count, dp);
        } else {
            nothing = maxProfit(prices, i+1, 0, count, dp);
            transaction = prices[i] + maxProfit(prices, i+1, 1, count-1, dp);
        }
        
        return dp[i][buy][count] = max(nothing, transaction);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int>(3, -1)));
        
        return maxProfit(prices, 0, 1, 2, dp);
    }
};