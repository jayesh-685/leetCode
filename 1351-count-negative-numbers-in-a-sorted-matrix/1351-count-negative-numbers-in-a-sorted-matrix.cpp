class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n=size(grid), m=size(grid[0]);
        int i=0, j=m-1;
        int ans=0;
        
        while (j>=0) {
            while (i<n && grid[i][j] >= 0) {
                i++;
            }
            ans += n-i;
            j--;
        }
        
        return ans;
        
    }
};