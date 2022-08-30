class Solution {
public:
    
//     even though the array is rotated, atleast one half of the array is still sorted so check which half is sorted and check if our target lies in that half or the other
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        
        while (l<=r) {
            int m = l + (r-l)/2;
            if (nums[m] == target)
                return m;
            
            // if left half is sorted
            if (nums[l] <= nums[m]) {
//                 if element lies in left half
                if (target>=nums[l] && target<nums[m]) {
                    r=m-1;
//                     else it lies in right half
                } else {
                    l=m+1;
                }
            } else {  // if right half is sorted
//                 if element lies in right half
                if (target>nums[m] && target<=nums[r]) {
                    l=m+1;
//                     else it lies in left half
                } else {
                    r=m-1;
                }
            }
        }
        
        return -1;
    }
};