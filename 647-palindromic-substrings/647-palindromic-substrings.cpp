class Solution {
public:
    string str;
    void solve (int i, int j, int& count) {
        if (i<0 || j>=str.length() || str[i]!=str[j])
            return;
        
        count++;
        solve(i-1, j+1, count);
    }
    int countSubstrings(string s) {
        str = s;
        int ans=0;
        
        for (int i=0; i<s.length(); i++) {
            int count=0;
            solve(i, i, count); solve(i, i+1, count);
            ans += count;
        }
        
        return ans;
    }
};