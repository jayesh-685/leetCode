class Solution {
public:
//     convert into adj
//     time required is max of time required by each subordinate of head to inform their subordinates;
    vector <vector <int>> adj;
    
    int dfs (int i, vector<int>& informTime) {
        int maxTime=0;
        for (int x: adj[i]) {
            // maxTime = informTime[i] + max(maxTime, dfs(x, informTime));
            maxTime = max(maxTime, informTime[i]+dfs(x, informTime));
        }
        
        return maxTime;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(manager.size());
        for (int i=0; i<manager.size(); i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        
        return dfs(headID, informTime);
    }
};