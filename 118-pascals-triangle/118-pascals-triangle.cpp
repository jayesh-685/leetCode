class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector <int>> ans;
        vector <int> v {1};
        ans.push_back(v);
        
        for (int level=1; level<numRows; level++) {
            vector <int> v;
            for (int i=0; i<=level; i++) {
                if (i==0 || i==level) {
                    v.push_back(1);
                } else {
                    int x = ans[level-1][i-1] + ans[level-1][i];
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};