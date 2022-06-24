class Solution {
public:
    vector <vector <int>> grid;
    
    void dfs (int s, vector <int> &visited) {
        visited[s] = true;
        for (int x=0; x<grid[s].size(); x++) {
            if (grid[s][x] && x!=s && !visited[x]) {
                dfs(x, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        grid = isConnected;
        vector <int> visited (isConnected.size(), false);
        int count=0;
        for (int i=0; i<isConnected.size(); i++) {
            if (!visited[i]) {
                dfs(i, visited);
                count++;
            }
        }
        
        return count;
    }
};