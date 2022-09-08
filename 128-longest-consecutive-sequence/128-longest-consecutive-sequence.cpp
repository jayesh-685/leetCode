class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s (nums.begin(), nums.end());
        int res=0;
        
        for (auto num: nums) {
            if (s.find(num-1)==s.end()) {
                int length=0, currNum=num;
                while (s.find(currNum++)!=s.end())
                    length++;
                res = max(res, length);
            }
        }
        
        return res;
    }
};