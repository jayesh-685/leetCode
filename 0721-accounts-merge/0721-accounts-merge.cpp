class Solution {
public:
    unordered_set <string> visited;
    unordered_map <string, vector<string>> adj;
    
    void dfs (string mail, vector<string>& list) {
        visited.insert(mail);
        list.push_back(mail);
        
        for (string& nbr: adj[mail]) {
            if (visited.find(nbr) == end(visited)) {
                dfs(nbr, list);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for (vector<string>& acc: accounts) {
            int n=size(acc);
            string firstm = acc[1];
            for (int j=2; j<n; j++) {
                string mail = acc[j];
                adj[firstm].push_back(mail);
                adj[mail].push_back(firstm);
            }
        }
        
        vector<vector<string>> ans;
        for (vector<string>& acc: accounts) {
            string firstm = acc[1];
            if (visited.find(firstm) == end(visited)) {
                vector<string> list;
                list.push_back(acc[0]);
                dfs(acc[1], list);
                sort(begin(list)+1, end(list));
                ans.push_back(list);
            }
        }
        
        return ans;
    }
};