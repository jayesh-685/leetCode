class Solution {
public:
//     xor of any no with itself is 0 so start with initial value equal to array size and xor with index and value
    int missingNumber(vector<int>& nums) {
        int res=nums.size();
        for (int i=0; i<nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        
        return res;
    }
};