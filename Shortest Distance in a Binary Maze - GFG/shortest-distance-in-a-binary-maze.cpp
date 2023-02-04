//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if (source == destination)  return 0;
        int n=grid.size(), m=grid[0].size();
        
        queue < pair<int,int> > qu;
        qu.push(source);
        int ds[] = {-1, 0, 1, 0, -1};
        
        while (!qu.empty()) {
            int x=qu.front().first, y=qu.front().second;
            qu.pop();
            
            for (int i=0; i<4; i++) {
                int p=x+ds[i], q=y+ds[i+1];
                
                if (p>=0 && p<n && q>=0 && q<m && grid[p][q]!=0) {
                    if (grid[p][q]==1 || grid[p][q] > grid[x][y]+1) {
                        grid[p][q] = grid[x][y]+1;
                        qu.push({p, q});
                    }
                }
            }
        }
        
        int x=destination.first, y=destination.second;
        return grid[x][y]==1 ? -1 : grid[x][y]-1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends