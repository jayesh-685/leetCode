class Solution {
public:
    
    bool dfs (vector<vector<int>>& adj, vector<int>& visited, vector<int>& path, int s) {
        visited[s] = true;
        path [s] = true;
        
        for (auto nbr: adj[s]) {
            if (!visited[nbr] && dfs(adj, visited, path, nbr))
                return true;
            else if (path[nbr])
                return true;;
        }
        
        path[s] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        
        for (int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> visited(numCourses), path(numCourses);
        
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && dfs(adj, visited, path, i))
                return false;
        }
        
        return true;
    }
};