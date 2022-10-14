class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        
        while (l<r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target)        return mid;
            else if (nums[mid] < target)    l = mid+1;
            else                            r = mid-1;
        }
        
        if (nums[l] >= target)    return l;
        else if (nums[l]<target)  return l+1;
        else                         return l-1;
    }
};