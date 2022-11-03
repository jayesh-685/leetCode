class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size(), m=grid[0].size();
        
        vector<vector<vector<int>>> dp (n, vector<vector<int>>(m, vector<int>(m)));
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                dp[n-1][i][j] = i==j ? grid[n-1][i] : grid[n-1][i] + grid[n-1][j];
            }
        }
        
        // cout << ".." << endl;
        
        for (int i=n-2; i>=0; i--) {
            for (int j=0; j<m; j++) {
                for (int k=0; k<m; k++) {
                    dp[i][j][k] = j==k? grid[i][j] : grid[i][j]+grid[i][k];
                    
                    int ans=INT_MIN;
                    
                    for (int dx=-1; dx<=1; dx++) {
                        for (int dy=-1; dy<=1; dy++) {
                            if (!(j+dx<0 || k+dy<0 || j+dx>=m || k+dy>=m))
                                ans = max(ans, dp[i+1][j+dx][k+dy]);
                        }
                    }
                    
                    dp[i][j][k] += ans;
                    // cout << i << " " << j << " " << k << endl;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
};