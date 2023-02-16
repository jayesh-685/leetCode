//{ Driver Code Starts
// Initial Template for C++

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
    bool isValid (int& x, int& y, int& n, int& m) {
        return ( x>=0 && y>=0 && x<n && y<m );
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        disjointSet ds (n*m);
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        int dr[] = {-1, 0, 1, 0, -1};
        
        vector<int> ans;
        int cnt=0;
        
        for (int i=0; i<operators.size(); i++) {
            int x=operators[i][0], y=operators[i][1];
            
            if (vis[x][y]) {
                ans.push_back(cnt);
                continue;
            }
            
            vis[x][y] = true;
            cnt++;
            
            for (int j=0; j<4; j++) {
                int nx=x+dr[j], ny=y+dr[j+1];
                
                if (isValid(nx, ny, n, m) && vis[nx][ny]) {
                    int node = m*x + y, nnode = m*nx + ny;
                    if (ds.findPar(node) != ds.findPar(nnode)) {
                        cnt--;
                        ds.unionByRank(node, nnode);
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends