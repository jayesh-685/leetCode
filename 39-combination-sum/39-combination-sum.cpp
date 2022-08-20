class Solution {
public:
    vector<vector<int>> ans;
    void solve (int target, vector<int>& v, vector<int>& cand, int k) {
        if (target==0) {
            ans.push_back(v);
            return;
        }
        
        if (target<0 || k>=cand.size())
            return;
        
        v.push_back(cand[k]);
        solve(target-cand[k], v, cand, k);
        v.pop_back();
        solve(target, v, cand, k+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> temp;
        ans=temp;
        vector<int> v;
        solve(target, v, candidates, 0);
        return ans;
    }
};