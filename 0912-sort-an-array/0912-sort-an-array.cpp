class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int> pq (begin(nums), end(nums));
        int i=size(nums)-1;
        while (i>=0) {
            nums[i--] = pq.top(); pq.pop();
        }
        
        return nums;
    }
};