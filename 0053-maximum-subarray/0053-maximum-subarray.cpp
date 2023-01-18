class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, mx=INT_MIN;
        
        for (int num: nums) {
            sum += num;
            mx = max(sum, mx);
            if (sum<0)  sum=0;
        }
        
        return mx;
    }
};