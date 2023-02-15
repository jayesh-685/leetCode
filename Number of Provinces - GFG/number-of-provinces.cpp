//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        disjointSet ds (V);
        
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (adj[i][j]) {
                    ds.unionByRank(i, j);
                }
            }
        }
        
        int ans=0;
        for (int i=0; i<V; i++) {
            ans += (ds.par[i]==i);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends