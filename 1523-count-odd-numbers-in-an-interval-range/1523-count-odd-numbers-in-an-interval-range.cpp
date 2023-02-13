class Solution {
public:
    int countOdds(int low, int high) {
        int ans = ((high-low)/2 + high%2 + low%2);
        if (high%2 && low%2)    ans -= 1;
        
        return ans;
    }
};