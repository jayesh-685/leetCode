class Solution {
public:
    // use a variable to store minimum value so far
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0], maxProfit = 0, profit;
        for (int i=1; i<prices.size(); i++) {
            profit = prices[i]-minSoFar;
            maxProfit = max(maxProfit, profit);
            minSoFar = min(minSoFar, prices[i]);
        }
        
        return maxProfit;
    }
};