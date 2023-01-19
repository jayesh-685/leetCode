class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        mp[0] = 1;
        int sum=0, cnt=0;
        
        for (int i=0; i<size(nums); i++) {
            sum += nums[i];
            cnt += mp[sum-k];
            mp[sum]++;
        }
        
        return cnt;
    }
};