class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector <vector <int>> ans (n, vector <int> (m, INT_MAX));
        queue <pair<int, int>> q;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (!mat[i][j]) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int d[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int i=p.first, j=p.second;
            for (int k=0; k<4; k++) {
                int x = i+d[k], y = j+d[k+1];
                if (x>=0 && y>=0 && x<n && y<m) {
                    if (ans[x][y]>ans[i][j]+1) {
                        ans[x][y] = ans[i][j]+1;
                        q.push({x, y});
                    }
                }
            }
        }
        
        return ans;
    }
};