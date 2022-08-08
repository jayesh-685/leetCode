class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector <bool> dp (n, false);
        dp[n-1] = true;
        for (int i=n-2; i>=0; i--) {
            for (int k=1; i+k<n && k<=nums[i]; k++) {
                if (dp[i+k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};