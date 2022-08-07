class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum, currSum;
        maxSum = currSum = nums[0];
        for (int i=1; i<size(nums); i++) {
            currSum += nums[i];
            if (nums[i] > currSum)
                currSum = nums[i];
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};