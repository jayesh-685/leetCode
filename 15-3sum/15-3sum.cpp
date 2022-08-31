class Solution {
public:
    // burte force is just 3 for loops but to solve duplicate problem sort the array and if you have found the triplet for curr element and next element is also same then skip the next elemet.
//     for the curr element use the 2sum method to find the remaining two elements and in that too skip same elements once you have calculated 2sum using those 2 elements.
//     O(n^2)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        
        for (int i=0; i<n-2; i++) {
            if (i>0 && nums[i]==nums[i-1])
                continue;
            int left=i+1, right=n-1;
            while (left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if (sum>0) {
                    right--;
                } else if (sum<0) {
                    left++;
                } else {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    left++; right--;
                    while (left<right && nums[left]==nums[left-1])  left++;
                    while (left<right && nums[right]==nums[right+1])  right--;
                }
            }
        }
        
        return ans;
    }
};