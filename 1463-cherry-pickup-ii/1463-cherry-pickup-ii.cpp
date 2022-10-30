class Solution {
public:
    int solve (vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>>& dp) {
        if ((c1<0 || c2<0 || r>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size()))
            return -1;
        
        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        vector<int> ds = {-1, 0, 1};
        int v1=grid[r][c1];
        int v2=grid[r][c2];
        if (c1==c2) v2=0;        
        int maxS=0;
        // cout << r << " " << c1 << " " << c2 << endl;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                    maxS = max(maxS, solve(grid, r+1, c1+ds[i], c2+ds[j], dp));
            }
        }
        return dp[r][c1][c2] = v1 + v2 + maxS;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int>(m, -1)));
        return solve(grid, 0, 0, grid[0].size()-1, dp);
    }
};