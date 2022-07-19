class Solution {
public:
// can do using finding freq of each element or sorting but this is better
//     or find sum of all unique elements, double it, subtract from sum of original array
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};