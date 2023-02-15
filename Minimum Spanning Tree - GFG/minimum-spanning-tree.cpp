//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointSet {
    public:
    vector<int> par, rank;
    
    disjointSet (int n) {
        par.resize(n+1);
        rank.resize(n+1, 0);
        
        for (int i=0; i<n+1; i++)   par[i]=i;
    }
    
    int findPar (int node) {
        if (par[node] == node)  return node;
        
        return par[node] = findPar(par[node]);
    }
    
    void unionByRank (int n1, int n2) {
        int p1=findPar(n1), p2=findPar(n2);
        
        if (p1 != p2) {
            // if we merge smaller set with larger set then there is no change in rank of either of the sets
            // rank only changes if we merge sets with equal rank
            if (rank[p1] < rank[p2]) {
                par[p1] = p2;
            } else if (rank[p2] < rank[p1]) {
                par[p2] = p1;
            } else {
                par[p1] = p2;
                rank[p2]++;
            }
        }
    }
    
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector< pair<int, pair<int,int>> > edges;
        
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        disjointSet ds (V);
        sort(begin(edges), end(edges));
        
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findPar(u) != ds.findPar(v)) {
                mstWt += wt;
                ds.unionByRank(u, v);
            }
        }

        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends