class Solution {
public:
    // include prev sum iff it is positive
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        vector <int> sum (n);
        sum[0] = nums[0];
        for (int i=1; i<n; i++) {
            sum[i] = nums[i] + (sum[i-1]<0?0:sum[i-1]);
            res = max(res, sum[i]);
        }

        return res;
    }
};