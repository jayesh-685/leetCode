class Solution {
public:
    // it's a directed graph so you can't start dfs from any arbitray node, you need to consider all paths from all nodes which will be O(nm)*n. 
    // we will be storing count for all colors for all nodes so that we don't need to recompute it again and again.
    // for ex if there is edge from 2-3 and 2-4 and if we know count for 3 and 4 we will take max of those and add 1 to the color of 2.
    int dfs(int node, string& colors, vector<vector<int>>& adj, vector<vector<int>>& count,
            vector<bool>& visit, vector<bool>& inStack) {
        // If the node is already in the stack, we have a cycle.
        if (inStack[node]) {
            return INT_MAX;
        }
        if (visit[node]) {
            return 0;
        }
        // Mark the current node as visited and part of current recursion stack.
        visit[node] = true;
        inStack[node] = true;

        for (auto& neighbor : adj[node]) {
            if (dfs(neighbor, colors, adj, count, visit, inStack) == INT_MAX) {
                return INT_MAX;
            }
            for (int i = 0; i < 26; i++) {
                count[node][i] = max(count[node][i], count[neighbor][i]);
            }
        }

        // After all the incoming edges to the node are processed,
        // we count the color on the node itself.
        count[node][colors[node] - 'a']++;
        // Remove the node from the stack.
        inStack[node] = false;
        return *max_element(begin(count[node]), end(count[node]));
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> count(n, vector<int>(26));
        vector<bool> visit(n), inStack(n);
        int answer = 0;
        for (int i = 0; i < n; i++) {
            answer = max(answer, dfs(i, colors, adj, count, visit, inStack));
        }

        return answer == INT_MAX ? -1 : answer;
    }
};