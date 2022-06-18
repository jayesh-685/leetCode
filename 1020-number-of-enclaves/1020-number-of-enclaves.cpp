class Solution {
public:
    
    int size, total, r, c;
    bool isEnclave;
    
    void solve (vector<vector<int>> &grid, int i, int j) {
        if (i<0 || j<0 || i>=r || j>=c) {
            isEnclave = false;
            return;
        }
        if (grid[i][j] == 0) {
            return;
        }
        
        size++;
        grid[i][j] = 0;
        
        solve(grid, i-1, j);
        solve(grid, i, j+1);
        solve(grid, i+1, j);
        solve(grid, i, j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        size=0, total=0;
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j]) {
                    isEnclave = true;
                    size = 0;
                    solve(grid, i, j);
                    if (isEnclave) {
                        total += size;
                    }
                }
            }
        }
        
        return total;
    }
};