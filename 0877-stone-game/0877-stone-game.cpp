class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int c=size(piles);
        vector<vector<int>> dp (c, vector<int>(c, 0));
        
        for (int i=0; i<c; i++) dp[i][i] = piles[i];
        
        for (int g=1; g<c; g++) {
            for (int l=0,r=g; r<c; l++,r++) {
                int turn = (r-l)%2;
                if (turn) {
                    int op1 = piles[l] + dp[l+1][r];
                    int op2 = piles[r] + dp[l][r-1];
                    dp[l][r] = max(op1, op2);
                } else {
                    int op1 = dp[l+1][r] - piles[l];
                    int op2 = dp[l][r-1] - piles[r];
                    dp[l][r] = min(op1, op2);
                }
            }
        }
        
        return dp[0][c-1]>0;
    }
};