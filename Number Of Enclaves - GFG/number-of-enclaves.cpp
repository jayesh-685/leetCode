//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs (vector<vector<int>>& grid, int i, int j, int n, int m) {
        
        if (i<0 || j<0 || i==n || j==m || grid[i][j]==0)    return;
        
        grid[i][j]=0;
        dfs(grid, i-1, j, n, m);
        dfs(grid, i, j-1, n, m);
        dfs(grid, i, j+1, n, m);
        dfs(grid, i+1, j, n, m);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n=grid.size(), m=grid[0].size();
        
        for (int i=0; i<n; i++) {
            if (grid[i][0])     dfs(grid, i, 0, n, m);
            if (grid[i][m-1])   dfs(grid, i, m-1, n, m);
        }
        
        for (int i=0; i<m; i++) {
            if (grid[0][i])     dfs(grid, 0, i, n, m);
            if (grid[n-1][i])   dfs(grid, n-1, i, n, m);
        }
        
        int ans=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                ans += grid[i][j];
            }
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends