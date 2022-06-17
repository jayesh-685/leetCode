class Solution {
public:
    
    int r, c;
    bool isClosed;
    
    void solve (vector<vector<int>> &grid, int i, int j) {
        if (i<0 || j<0 || i>=r || j>=c) {
            isClosed = false;
            return;
        }
        if (grid[i][j] == 1)
            return;
        
        grid[i][j] = 1;
        
        solve(grid, i-1, j);
        solve(grid, i, j+1);
        solve(grid, i+1, j);
        solve(grid, i, j-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        r=grid.size(); c=grid[0].size();
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j]==0) {
                    isClosed = true;
                    solve(grid, i, j);
                    if(isClosed)
                        count++;
                }
            }
        }
        
        return count;
    }
};