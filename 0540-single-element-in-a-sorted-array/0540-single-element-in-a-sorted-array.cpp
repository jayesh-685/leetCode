class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=size(nums)-1;
        
        while (l<r) {
            int m = l + (r-l)/2;
            
            if (nums[m]!=nums[m-1] && nums[m]!=nums[m+1]) {
                return nums[m];
            }
            
            if ((m-l)%2) {
                if (nums[m+1] != nums[m]) l=m+1;
                else                      r=m-1;
            } else {
                if (nums[m+1] != nums[m]) r=m;
                else                      l=m;
            }
        }
        
        return nums[l];
    }
};