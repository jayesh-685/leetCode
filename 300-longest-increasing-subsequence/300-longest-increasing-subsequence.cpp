class Solution {
public:
//     if arr[i] > arr[j] where i>j then length of lis ending at i = 1+ length of lis ending at j
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int res=1;
        vector <int> dp (n, 1); // because even if all elements are in decreases order still lis length is 1
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[j]<nums[i]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                    res = max(res, dp[i]);
                }
            }
        }
        
        return res;
    }
};