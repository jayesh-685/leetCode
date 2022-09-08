class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=cost[0], b=cost[1], c, n=cost.size();
        if (n<3)
            return min(a, b);
        
        for (int i=2; i<n; i++) {
            c = min(a,b) + cost[i];
            a=b; b=c;
        }
        
        return min(c, a);
    }
};