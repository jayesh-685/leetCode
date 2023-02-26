class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int lsum=0, rsum=accumulate(begin(nums), end(nums), 0);
        int n=size(nums);
        
        vector<int> ans (n, 0);
        for (int i=0; i<n; i++) {
            rsum -= nums[i];
            ans[i] = abs(rsum-lsum);
            lsum += nums[i];
        }
        
        return ans;
    }
};