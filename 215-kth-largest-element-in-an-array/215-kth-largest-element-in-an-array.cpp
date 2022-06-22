class Solution {
public:
    
//     based on quick sort
//     if k (=length-k that is index of k largest element) is equal to pivot then we have found our answer else if it greater than pivot then we apply quick select for right part of pivot else for left part
    int K;
    int quickSelect (int l, int r, vector<int>& nums) {
        int pivot=r, index=l;
        for (int i=l; i<r; i++) {
            if (nums[i]<=nums[pivot]) {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        
        swap(nums[index], nums[pivot]);
        
        int length = nums.size();
        if (length-K > index)       return quickSelect(index+1, r, nums);
        else if (length-K<index)    return quickSelect(l, index-1, nums);
        else                        return nums[index];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        K = k;
        return quickSelect(0, nums.size()-1, nums);
    }
};
 