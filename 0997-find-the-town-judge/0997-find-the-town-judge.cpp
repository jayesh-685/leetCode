class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> id (n+1), od(n+1);
        
        for (auto t: trust) {
            id[t[1]]++;
            od[t[0]]++;
        }
        
        int ans=-1;
        for (int i=1; i<=n; i++) {
            if (id[i]==n-1 && od[i]==0) {
                return i;
            }
        }
        
        return -1;
    }
};