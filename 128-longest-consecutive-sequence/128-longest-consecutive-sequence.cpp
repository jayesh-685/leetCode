class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size())
            return 0;
        unordered_set <int> s;
        for (auto x: nums)
            s.insert(x);
        
        int ls=1, st=1;
        for (auto x: nums) {
            if (s.find(x-1) == s.end()) {
                while (s.find(x+1) != s.end()) {
                    st++; x++;
                }
                
                ls = max(ls, st);
                st = 1;
            }
        }
        
        return ls;
    }
};