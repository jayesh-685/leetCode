class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        
        return abs((n*(n-1)/2)-accumulate(nums.begin(), nums.end(), 0));
    }
};