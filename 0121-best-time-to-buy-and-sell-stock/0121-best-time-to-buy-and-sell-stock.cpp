class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, minEl=prices[0];
        for (int i=1; i<prices.size(); i++) {
            if (prices[i] >= minEl)
                ans = max(ans, prices[i]-minEl);
            else
                minEl = prices[i];
        }
        
        return ans;
    }
};