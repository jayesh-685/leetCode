class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(begin(candies), end(candies));
        vector<bool> ans (size(candies));
        
        for (int i=0; i<size(candies); i++) {
            if (candies[i]+extraCandies >= mx)  ans[i]=true;
        }
        
        return ans;
    }
};