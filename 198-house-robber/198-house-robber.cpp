class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int without=0, with=nums[0];
        
        
        for (int i=1; i<n; i++) {
            int prevWithout = without;
            without = max(without, with);
            with = prevWithout + nums[i];
        }
        
        return max(with, without);
    }
};