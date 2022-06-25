// if ith element is greater than i+1 element then you can either make i+1 element equal to i element (for that i+1 element should be >= i-1 element) or you can make i element equal to i+1 element but we prefer to do the former since we have info about the prev elements but not the new elements.
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed = false;
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i]>nums[i+1]) {
                if (changed)
                    return false;
                if (i==0 || nums[i+1]>=nums[i-1])
                    nums[i]=nums[i+1];
                else
                    nums[i+1] = nums[i];
                changed = true;
            }
        }
        
        return true;
    }
};