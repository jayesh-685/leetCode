class Solution {
public:
//     in nums[i] > num[j] then length of lis start with nums[i] = length of lis starting with nums[j] + 1
    int lengthOfLIS(vector<int>& nums) {
        vector <int> dp (nums.size(), 1);
        int ans=1, n=nums.size();
        
        for (int i=1; i<n; i++) {
            // cout << i << endl;
            for (int j=0; j<i; j++) {
                if (nums[j]<nums[i]) {
                    // cout << "hello" << endl;
                    dp[i] = max(dp[i], dp[j]+1);
                    ans = max(ans, dp[i]);
                    // cout << ans << endl;
                }
            }
        }
        
        return ans;
    }
};