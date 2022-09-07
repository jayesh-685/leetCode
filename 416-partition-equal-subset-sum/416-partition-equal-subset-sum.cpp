class Solution {
public:
    bool solve (int i, vector<int>& nums, int set1, int sum, vector<vector<int>>& dp) {
        
        if (i==nums.size())
            return (double)set1==(double)sum/2;
        
        if (dp[i][set1]!=-1)
            return dp[i][set1];
                    
        return dp[i][set1]=solve(i+1, nums, set1+nums[i], sum+nums[i], dp) || solve(i+1, nums, set1, sum+nums[i], dp);
    }
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> dp (n, vector<int>(accumulate(nums.begin(), nums.end(), 0)+1, -1));
        return solve(0, nums, 0, 0, dp);
    }
};