//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool fill (vector<int> adj[], int s, vector<int>& colors) {
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
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colors (V, -1);
	    
	    for (int i=0; i<V; i++) {
	        if (colors[i] == -1) {
	            if (fill(adj, i, colors) == false)
	                return false;
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends