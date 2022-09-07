class Solution {
public:
    int solve (int i, vector<int>& nums, int n) {
        int with=nums[i], without=0;
        
        for (int j=i+1; j<n; j++) {
            int newWith = without+nums[j];
            int newWithout = max(with, without);
            
            with = newWith; without = newWithout;
        }
        
        return max(with, without); 
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if (n==1)
            return nums[0];
        
        return max(solve(0, nums, n-1), solve(1, nums, n));
    }
};