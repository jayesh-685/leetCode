class Solution {
public:
//     start from second last index. if you can reach the last index from the second last index, set the last index as last index and try from third last index and so on...
    bool canJump(vector<int>& nums) {
        int n=nums.size(), last=n-1;
        for (int i=n-2; i>=0; i--) {
            if (i+nums[i] >= last)
                last = i;
        }
        
        return last==0;
    }
};