//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs (vector<int> graph[], vector<int>& visited, vector<int>& path, int s) {
        
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
    
    vector<int> eventualSafeNodes(int v, vector<int> graph[]) {
        // code here
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends