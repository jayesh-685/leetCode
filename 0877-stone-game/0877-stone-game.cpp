class Solution {
public:
    // since alice is starting first alice can choose all the odd indexed stones or all the even indexed stones and since the sum is even sum of odd indexed stones is always less than or greater than the even indexd stones so alice can choose whichever is higher.
    
    
    // solution in case sum is not even:
    
    // we can re-think the problem as: instead of alice try to maximize his sum and bob trying to maximize his, think of it as alice trying to maximize a particular sum variable and bob trying to minimize it 
    
    // if it is Alice's turn we will maximize the sun and if it bob's turn we will try to minimize the sum
    
    int dp[1005][1005];
    int solve (vector<int>& piles, int l, int r, int turn) {
        
        if (l>r)    return 0;
        
        if (dp[l][r] != -1) return dp[l][r];
        
        if (turn) {
            int op1 = piles[l] + solve(piles, l+1, r, 0);
            int op2 = piles[r] + solve(piles, l, r-1, 0);
            return dp[l][r] = max(op1, op2);
        } else {
            int op1 = solve(piles, l+1, r, 1) - piles[l];
            int op2 = solve(piles, l, r-1, 1) - piles[r];
            return dp[l][r] = min(op1, op2);
        }
    }
    bool stoneGame(vector<int>& piles) {
        
        memset(dp, -1, sizeof(dp));
        return solve(piles, 0, size(piles)-1, 1)>0;
    }
};