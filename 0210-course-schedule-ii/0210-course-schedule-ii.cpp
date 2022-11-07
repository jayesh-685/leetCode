class Solution {
public:
    
    bool dfs (vector<vector<int>>& adj, vector<int>& visited, vector<int>& path, int s, stack <int>& st, vector<int>& ans) {
        visited[s] = true;
        path [s] = true;
        st.push(s);
        
        for (auto nbr: adj[s]) {
            if (!visited[nbr] && dfs(adj, visited, path, nbr, st, ans))
                return true;
            else if (path[nbr])
                return true;;
        }
        
        ans.push_back(s);
        st.pop();
        path[s] = false;
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        
        for (int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> visited(numCourses), path(numCourses), ans;
        stack <int> st;
        
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && dfs(adj, visited, path, i, st, ans)) {
                vector<int> v;
                return v;
            }
        }
        
        return ans;
    }
};