class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp (coins.size(), vector<int>(amount+1));
        
        for (int i=0; i<=amount; i++) 
            if (i%coins[0]==0)
                dp[0][i]=1;
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<=amount; j++) {
                dp[i][j] = dp[i-1][j];
                if (j-coins[i]>=0)
                    dp[i][j]+=dp[i][j-coins[i]];
            }
        }
        
        return dp[n-1][amount];
    }
};