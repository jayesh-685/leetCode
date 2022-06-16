class Solution {
public:
    
    int COLOR;
    int OGCOLOR;
    int R, C;
    
    void solve (vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        if (i<0 || j<0 || i>=R || j>=C || visited[i][j] || grid[i][j]!=OGCOLOR)
            return;
        
        visited[i][j] = true;
        grid[i][j] = COLOR;
        
        // solve(grid, i-1, j-1, visited, r, c);
        solve(grid, i-1, j, visited);
        // solve(grid, i-1, j+1, visited, r, c);
        solve(grid, i, j+1, visited);
        // solve(grid, i+1, j+1, visited, r, c);
        solve(grid, i+1, j, visited);
        // solve(grid, i+1, j-1, visited, r, c);
        solve(grid, i, j-1, visited);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        R = grid.size();
        C = grid[0].size();
        
        vector <vector <bool>> visited (R, vector<bool>(C, false));
        
        COLOR = color;
        OGCOLOR = grid[sr][sc];
        solve(grid, sr, sc, visited);
        return grid;
    }
    
};

