class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector <int> lastOcc (10005, -1);
        int l=0, r=0;
        int cost=0, maxCost=0;
        int n = nums.size();
        vector <int> prefixSum (n+1);
        prefixSum[0]=0;
        for (int i=0; i<n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
            
        while (r<n) {
            if (lastOcc[nums[r]] != -1) {
                l = max(l, lastOcc[nums[r]]+1);
            }
            lastOcc[nums[r]] = r;
            // length = r-l+1;
            // res = max(res, length);
            cost = prefixSum[r+1] - prefixSum[l];
            maxCost = max(cost, maxCost);
            r++;
        }
        
        return maxCost;
    }
};