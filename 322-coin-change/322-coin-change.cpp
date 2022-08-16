class Solution {
public:
//     start from amount=0 and go till amount=amount
//     for each amount iterate over all the coins and if coin is less than amount update value of dp[amount]
//     ex if amount is 5 and coin value is 2 then minimum no of coins required for amount 5 is minimum no of coins required for amount 3 (5-2) + one 2 ruppee coin.
    int coinChange(vector<int>& coins, int amount) {
//         can initialize with amount+1 or infinity
        vector <int> dp (amount+1, amount+1);
        dp[0] = 0;  // no coins for no amount
        
        for (int i=1; i<=amount; i++) {
            for (auto coin: coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], 1+dp[i-coin]);
                }
            }
        }
        
        return dp[amount]==amount+1? -1 : dp[amount];
    }
};