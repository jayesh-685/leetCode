class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ds[] = {-1, 0, 1, 0, -1};
        int n=heights.size(), m=heights[0].size();
        vector <vector <int>> pacific (n, vector<int>(m, false));
        queue <pair<int, int>> q;
        for (int i=0; i<n; i++) {
            q.push({i, 0});
            pacific[i][0] = true;
        }
        for (int i=0; i<m; i++) {
            pacific[0][i] = true;
            q.push({0, i});
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();    q.pop();
            pacific[x][y] = true;
            for (int i=0; i<4; i++) {
                int p=x+ds[i], r=y+ds[i+1];
                if (p>=0 && r>=0 && p<n && r<m && heights[p][r]>=heights[x][y] && !pacific[p][r])
                    q.push({p, r});
            }
        }
        
        vector <vector <int>> atlantic (n, vector<int>(m, false));
        for (int i=0; i<n; i++) {
            q.push({i, m-1});
            atlantic[i][m-1] = true;
        }
        for (int i=0; i<m; i++) {
            atlantic[n-1][i] = true;
            q.push({n-1, i});
        }
        
        while (!q.empty()) {
            auto [x, y] = q.front();    q.pop();
            atlantic[x][y] = true;
            for (int i=0; i<4; i++) {
                int p=x+ds[i], r=y+ds[i+1];
                if (p>=0 && r>=0 && p<n && r<m && heights[p][r]>=heights[x][y] && !atlantic[p][r])
                    q.push({p, r});
            }
        }
        
        vector<vector<int>> ans;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector <int> temp = {i, j};
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
        
    }
};