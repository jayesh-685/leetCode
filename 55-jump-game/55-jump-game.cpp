class Solution {
public:
    vector <int> dp;
    bool solve(vector<int>& jumps, int i, int n) {
        if(i>=n-1)
            return true;
        
        if (dp[i] != -1)
            return dp[i];
        for (int k=1; k<=jumps[i]; k++)
            if (solve(jumps, i+k, n))
                return dp[i]=true;
        
        return dp[i]=false;
    }
    bool canJump(vector<int>& jumps) {
        vector <int> temp(jumps.size(), -1);
        dp = temp;
        return solve(jumps, 0, jumps.size());
    }
};