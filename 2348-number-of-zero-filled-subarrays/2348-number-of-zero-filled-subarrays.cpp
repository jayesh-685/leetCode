class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long n=size(nums), len=0;
        long long ans=0;
        
        for (int i=0; i<n; i++) {
            if (nums[i]==0) {
                len++;
            } else {
                if (len) {
                    ans += (len*(len+1)/2);
                    len=0;
                }
            }
        }
        
        if (len)    ans += (len*(len+1)/2);
        return ans;
    }
};