class Solution {
public:
    int memo[10001];
    int solve (vector<int>& coins, int amount) {
        if (amount<0)
            return -1;
        if (amount==0)
            return 0;
        
        if (memo[amount] != 0)
            return memo[amount];
        
        int ans=INT_MAX;
        
        for (int i=0; i<coins.size(); i++) {
            int res = coinChange(coins, amount-coins[i]);
            if (res!=INT_MAX && res!=-1) {
                ans = min(ans, 1+res);
            }
        }
        
        return memo[amount] = ans==INT_MAX ? -1 : ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount);
    }
};