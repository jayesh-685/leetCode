class Solution {
public:
    bool dfs (vector<vector<int>>& graph, vector<int>& visited, vector<int>& path, int s) {
        
        visited[s]=true;    path[s]=true;
        
        for (auto x: graph[s]) {
            if (!visited[x] && dfs(graph, visited, path, x))
                return true;
            if (path[x])
                return true;
        }
        
        path[s] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // except those nodes involved in a cycle, all nodes are safe nodes.
        // if a node is involved in a cycle, it is not unmarked from path array so we can use path array to find out safe nodes
        
        int v=graph.size();
        vector<int> visited(v), path(v);
        
        for (int i=0; i<v; i++) {
            if (!visited[i])
                dfs(graph, visited, path, i);
        }
        
        vector<int> ans;
        
        for (int i=0; i<v; i++) {
            if (!path[i])
                ans.push_back(i);
        }
        
        return ans;
        
    }
};