class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];
        
        int cost=0;
        for (auto x: nums)
            cost += abs(x-median);
        
        return cost;
    }
};