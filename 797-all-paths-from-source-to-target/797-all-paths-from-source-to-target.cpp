class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> temp;
    
    void dfs (vector<vector<int>> &graph, int p) {
        temp.push_back(p);
        if (p == graph.size()-1) {
            ans.push_back(temp);
            return;
        }
        for (int x: graph[p]) {
            dfs(graph, x);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }
};