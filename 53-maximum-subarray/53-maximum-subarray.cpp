class Solution {
public:
//     if after adding the curr no the currSum becomes smaller, we don't need the previous sub array so we set currSum to currElement
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