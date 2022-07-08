class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int sum[2][n];
        
        sum[0][0] = 0;  sum[1][0] = nums[0];
        
        for (int i=1; i<n; i++) {
            sum[0][i] = max(sum[1][i-1], sum[0][i-1]);
            sum[1][i] = sum[0][i-1] + nums[i];
        }
        
        return max(sum[0][n-1], sum[1][n-1]);
    }
};