// check notes
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        //Sort the array
        sort(nums.begin(), nums.end());
        
        //Find the median
        int median = n%2==0 ? (nums[n/2]+nums[n/2-1])/2 : nums[n/2];
        int steps = 0;
        
        //Calculate steps
        for(int num : nums) {
            steps += abs(num-median);
        }
        
        return steps;
    }
};