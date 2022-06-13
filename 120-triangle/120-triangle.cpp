class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector <int> dp = triangle[n-1];
        for (int level=n-2; level>=0; level--) {
            for (int i=0; i<=level; i++) {
                dp[i] = triangle[level][i] + min(dp[i], dp[i+1]);
            }
        }

        return dp[0];
    }
};