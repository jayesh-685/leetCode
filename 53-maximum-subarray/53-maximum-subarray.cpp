class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum, currSum;
        maxSum = currSum = nums[0];
        for (int i=1; i<size(nums); i++) {
            if (nums[i] >= 0) {
                if (currSum >= 0) {
                    currSum += nums[i];
                } else {
                    currSum = nums[i];
                }
                maxSum = max(currSum, maxSum);
            } else {
                if (currSum < 0) {
                    currSum += nums[i];
                    maxSum = max(maxSum, nums[i]);
                } else {
                    currSum += nums[i];
                }
            }
            // cout << currSum << " " << maxSum << endl;
        }
        
        return maxSum;
    }
};