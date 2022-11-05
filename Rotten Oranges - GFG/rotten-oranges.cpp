//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isValid (int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue <pair<int, int>> q;
        int gc=0, n=grid.size(), m=grid[0].size(), tt=0;
        int ds[] = {-1, 0, 1, 0, -1};
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]==2)
                    q.push({i, j});
                else if (grid[i][j]==1)
                    gc++;
            }
        }
        
        q.push({-1, -1});
        
        while (gc && q.size()>1) {
            while (q.front().first != -1) {
                auto temp = q.front(); q.pop();
                int i=temp.first, j=temp.second;
                for (int k=0; k<4; k++) {
                    int x=i+ds[k], y=j+ds[k+1];
                    if (isValid(x, y, n, m) && grid[x][y]==1) {
                        grid[x][y]=2;
                        q.push({x, y});
                        gc--;
                    }
                }
            }
            q.pop();    
            q.push({-1, -1});
            tt++;
        }
        
        return gc ? -1 : tt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends