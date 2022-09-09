class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> mp;
        int maxLength=1, n=s.length();
        if (n<2)    return n;
        int l=0, r=1;
        mp[s[l]]=0;
        
        while (r<n) {
            if (mp.find(s[r])==mp.end() || mp[s[r]]<l) {
                maxLength = max(maxLength, r-l+1);
            } else {
                l = mp[s[r]]+1;
            }
            mp[s[r]]=r;
            r++;
        }
        
        return maxLength;
    }
};