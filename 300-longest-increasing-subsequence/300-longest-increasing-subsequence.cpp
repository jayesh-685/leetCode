class Solution {
public:
//     if no elements return 0;
//     memo
    vector <vector <int>> dp;
    int lis (vector<int>& nums, int i, int n, int prev) {
        
        if (i==n)
            return 0;
        
        if (dp[i][prev+1] != -1)
            return dp[i][prev+1];
        
        if (prev==-1 || nums[i] > nums[prev])
            return dp[i][prev+1] = max(lis(nums, i+1, n, prev), 1+lis(nums, i+1, n, i));
        return dp[i][prev+1] = (lis(nums, i+1, n, prev));
        
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector <vector <int>> temp(n, vector <int> (n+1, -1));
        dp = temp;
        return lis(nums, 0, nums.size(), -1);
    }
};