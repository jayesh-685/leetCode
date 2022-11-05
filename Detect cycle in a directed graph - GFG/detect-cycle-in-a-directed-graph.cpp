//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool solve (vector<int> adj[], vector<bool>& visited, vector<bool>& path, int s) {
        
        visited[s]=true; path[s]=true;
        
        for (auto x: adj[s]) {
            if (!visited[x] && solve(adj, visited, path, x))
                return true;

            else if (path[x])
                return true;
        }
        
        path[s]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V), path(V);
        
        for (int i=0; i<V; i++) {
            if (!visited[i] && solve(adj, visited, path, i))
                return true;
        }
        
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends