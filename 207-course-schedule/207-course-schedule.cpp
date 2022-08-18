class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector <vector <int>> adj (n);
        vector <int> indegree (n, 0);
        for (auto edge: prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        
        for (int i=0; i<n; i++) {
            int j;
            for (j=0; j<n; j++) {
                if (indegree[j]==0)
                    break;
            }
            
            if (j==n)
                return false;
            
            for (auto v: adj[j])
                indegree[v]--;
            
            indegree[j]--;
        }
        
        return true;
    }
};