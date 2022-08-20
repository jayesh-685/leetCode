class Solution {
public:
    vector<vector<int>> ans;
    void solve (int target, vector<int>& v, vector<int>& cand, int k) {
        if (target==0) {
            ans.push_back(v);
            return;
        }
        
        if (target<0)
            return;
        
        for (int i=k; i<cand.size(); i++) {
            v.push_back(cand[i]);
            solve(target-cand[i], v, cand, i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> temp;
        ans=temp;
        vector<int> v;
        solve(target, v, candidates, 0);
        return ans;
    }
};