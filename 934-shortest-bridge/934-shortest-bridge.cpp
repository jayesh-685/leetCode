class Solution {
public:
    int r, c;
    queue <pair<int, int>> q;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool checkBounds (int i, int j) {
        return (i>=0 && j>=0 && i<r && j<c);
    }
    
    void dfs (vector<vector<int>> &grid, int i, int j) {
        if (i<0 || j<0 || i>=r || j>=c || grid[i][j]!=1)
            return;
        
        q.push({i, j});
        grid[i][j] = 2;
        
        for (int k=0; k<4; k++)
            dfs(grid, i+dx[k], j+dy[k]);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        r=grid.size(), c=grid[0].size();
        
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j]) {
                    dfs(grid, i, j);
                    goto end;
                }
            }
        }
        
        end:
        // cout << "queue size: " << q.size() << endl; 
        
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for (int k=0; k<4; k++) {
                int m = i+dx[k], n = j+dy[k];
                if (checkBounds(m, n)) {
                    if (grid[m][n] == 1) {
                        return grid[i][j]-2;
                    } else if (grid[m][n] == 0) {
                        grid[m][n] = grid[i][j]+1;
                        q.push({m, n});
                    }
                }
            }
        }
        
        return 1;
    }
};