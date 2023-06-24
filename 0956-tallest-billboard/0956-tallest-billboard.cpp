class Solution {
public:
    int dp[21][10005];
    int solve (vector<int>& rods, int i, int val) {
        
        if (i==size(rods)) {
            return val==0 ? 0 : INT_MIN;
        }
        
        if (dp[i][val+5000] != -1)   return dp[i][val+5000];
        
        return dp[i][val+5000] = max({solve(rods, i+1, val), rods[i]+solve(rods, i+1, val+rods[i]), solve(rods, i+1, val-rods[i])});
    }
    int tallestBillboard(vector<int>& rods) {
        
        memset(dp, -1, sizeof(dp));
        return solve(rods, 0, 0);
    }
};