class Solution {
public:
    bool isPossible (vector<int>& weights, const int& cap, const int& days) {
        int cnt=1, total=0;
        for (int &wt: weights) {
            if (total+wt <= cap) {
                total += wt;
            } else {
                total = wt;
                cnt++;
            }
            
        }
        
        return cnt <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(begin(weights), end(weights)), r=accumulate(begin(weights), end(weights), 0);
        int ans;
        
        while (l<=r) {
            int m = l + (r-l)/2;
            
            if (isPossible(weights, m, days))   {
                ans = m;
                r=m-1;
            } else {
                l=m+1;
            }
        }
        
        return ans;
    }
};