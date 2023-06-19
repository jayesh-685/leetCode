class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int alt=0;
        for (int i=0; i<size(gain); i++) {
            alt += gain[i];
            ans = max(ans, alt);
        }
        
        return ans;
    }
};