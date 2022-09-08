class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0), n=nums.size();;
        if (k%2)   return false;
        k /= 2;
        
        vector<vector<bool>> dp (n+1, vector<bool>(k+1));
        
        for (int i=0; i<=n; i++)
            dp[i][0]=true;
        for (int i=1; i<=k; i++)
            dp[0][i]=false;
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=k; j++) {
                if (j-nums[i-1]>=0)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][k];
    }
};