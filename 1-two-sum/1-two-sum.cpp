class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (nums[j] == target-nums[i]) {
                    vector<int> v {i, j};
                    return v;
                }
            }
        }
        
        return nums;
    }
};