class Solution {
public:
//     if first elements < last element then array is not rotated so return the first element
//     if array is rotated then minimum element lies in that half which is not sorted so find that apply b.s on that half
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if (nums[0]<nums[n-1])
            return nums[0];
        
        int left=0, right=n-1;
        
        while (left<=right) {
            if (right-left==1 || right-left==0)
                return min(nums[left], nums[right]);
            
            int mid = left + (right-left)/2;
            
            if (nums[left]<=nums[mid]) {
                left=mid;
            } else {
                right=mid;
            }
        }
        
        return -1;
    }
};