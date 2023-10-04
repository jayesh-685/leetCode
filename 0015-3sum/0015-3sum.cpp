class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int n=size(nums);
        
        for (int i=0; i<n-2; i++) {
            int target=-nums[i];
            int l=i+1, r=n-1;
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            while (l<r) {
                if (nums[l]+nums[r] == target) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while (l<r && nums[l]==nums[l-1]) l++;
                    while (l<r && nums[r]==nums[r+1]) r--;
                } else if (nums[l]+nums[r] < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        
        return ans;
    }
};