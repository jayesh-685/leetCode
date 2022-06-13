class Solution {
public:
//     bottom up dp approach
//     create an array that stores the last level and start from second last level
//     for each index calculate the shortest path value by getting the min of i and i+1 index of next level.
//     since for each level we only need the level which is just below the current level we reuse the same array.
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
