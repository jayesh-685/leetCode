class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans (n);
        ans[n-1] = nums[n-1];
        
        for (int i=n-2; i>=0; i--) {
            ans[i] = ans[i+1]*nums[i];
        }
        
        int prefix=1;
        
        for (int i=0; i<n-1; i++) {
            ans[i] = ans[i+1]*prefix;
            prefix*=nums[i];
        }
        
        ans[n-1] = prefix;
        
        return ans;
    }
};