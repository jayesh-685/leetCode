class Solution {
public:
    // partioning similar to quick sort
    // all nos to the left of left are 0, and to right of right are 1
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0, left=0, right=n-1;
        while (i<=right) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left++; i++;
            } else if (nums[i] == 1) {
                i++;
            } else {
                swap(nums[right], nums[i]);
                right--;
                // here we won't move i because it is possible that right was pointing to a 0 so after swapping a 0 is now present between left and right pointers which is wrong.
            }
        }
    }
};