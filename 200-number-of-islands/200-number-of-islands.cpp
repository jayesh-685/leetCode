class Solution {
  public:
    // Function to find the number of islands.
    
    void numIslandsHelper (const vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited, int r, int c) {
        if (i<0 || j<0 || i>=r || j>=c || visited[i][j] || grid[i][j]=='0')
            return;
        
        visited[i][j] = true;
        // numIslandsHelper(grid, i-1, j-1, visited, r, c);
        numIslandsHelper(grid, i-1, j, visited, r, c);
        // numIslandsHelper(grid, i-1, j+1, visited, r, c);
        numIslandsHelper(grid, i, j+1, visited, r, c);
        // numIslandsHelper(grid, i+1, j+1, visited, r, c);
        numIslandsHelper(grid, i+1, j, visited, r, c);
        // numIslandsHelper(grid, i+1, j-1, visited, r, c);
        numIslandsHelper(grid, i, j-1, visited, r, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int r = grid.size();
        int c = grid[0].size();
        // initializing a 2d vector
        vector <vector <bool>> visited (r, vector<bool>(c, false));

        int count = 0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (grid[i][j]=='1' && !visited[i][j]) {
                    count++;
                    numIslandsHelper(grid, i, j, visited, r, c);
                }
            }
        }
        
        return count;
    }
};