class Solution {
public:
    bool fill (vector<vector<int>>& adj, int s, vector<int>& colors) {
        colors[s]=0;
        
        queue<int> q;
        q.push(s);
        
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            
            for (auto nbr: adj[curr]) {
                if (colors[nbr] == -1) {
                    q.push(nbr);
                    colors[nbr] = !colors[curr];
                } else {
                    if (colors[nbr] == colors[curr])
                        return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> colors (V, -1);
	    
	    for (int i=0; i<V; i++) {
	        if (colors[i] == -1) {
	            if (fill(graph, i, colors) == false)
	                return false;
	        }
	    }
	    
	    return true;
    }
};