//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        disjointSet ds (n);
        for (auto &e: edge) {
            int n1=e[0], n2=e[1];
            ds.unionByRank(n1, n2);
        }
        
        int cnt=0;
        for (int i=0; i<n; i++) {
            cnt += (ds.par[i]==i);
        }
        
        if (edge.size() >= n-1) {
            return cnt-1;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends