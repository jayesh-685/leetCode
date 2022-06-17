class Solution {
public:
    
    int R, C;
    int count=0, maxCount=0;
    
    void solve (vector<vector<int>>& grid, vector <vector <int>> &visited, int i, int j) {
        if (i<0 || j<0 || i>=R || j>=C || visited[i][j] || grid[i][j]==0)
            return;
        
        count++;
        visited[i][j] = 1;
        
        solve(grid, visited, i-1, j);
        solve(grid, visited, i, j+1);
        solve(grid, visited, i+1, j);
        solve(grid, visited, i, j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        vector <vector <int>> visited (R, vector <int> (C, 0));
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    count=0;
                    solve(grid, visited, i, j);
                    maxCount = max(maxCount, count);
                }
            }
        }
        
        return maxCount;
    }
};