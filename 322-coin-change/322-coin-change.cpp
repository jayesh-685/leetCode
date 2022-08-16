class Solution {
public:
    vector <int> dp;
    int solve (vector<int>& coins, int rem) {
        
        if (rem<0)  return -1;
        if (rem==0) return 0;
        
        if (dp[rem-1] != 0) return dp[rem-1];
        
        int ans = INT_MAX;
        for (auto coin: coins) {
            int res = solve(coins, rem-coin);
            if (res>=0 && res<ans)
                ans = res+1;
        }
        
        return dp[rem-1] = (ans==INT_MAX ? -1 : ans);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1) return 0;
        vector <int> temp (amount);
        dp = temp;
        return solve(coins, amount);
    }
};