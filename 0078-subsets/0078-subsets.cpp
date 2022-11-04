class Solution {
public:
    void solve (vector<int>& nums, vector<int>& v, int i, vector<vector<int>>& ans) {
        if (i==nums.size()) {
            ans.push_back(v);
            return;
        }
        
        solve(nums, v, i+1, ans);
        v.push_back(nums[i]);
        solve(nums, v, i+1, ans);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(nums, v, 0, ans);
        return ans;
    }
};