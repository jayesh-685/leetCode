class Solution {
public:
    unordered_map <int, int> memo;
    int solve (vector<int>& cost, int i) {
        if (memo.find(i) != memo.end())
            return memo[i];
        int n=cost.size();
        if (i==n)
            return memo[i]=0;
        
        if (i==n-1)
            return memo[i]=cost[i];
        
        return memo[i]=cost[i]+min(solve(cost, i+1), solve(cost, i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost, 0), solve(cost, 1));
    }
};