class Solution {
public:
//     indegree-outdegree is n-1
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector <int> degree (n+1, 0);
        for (int i=0; i<trust.size(); i++) {
            int x=trust[i][0], y=trust[i][1];
            degree[x]--; degree[y]++;
        }
        
        for (int i=1; i<=n; i++) 
            if (degree[i] == n-1)
                return i;
        return -1;
    }
};