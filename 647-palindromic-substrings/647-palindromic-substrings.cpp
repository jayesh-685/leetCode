class Solution {
public:
    int count;
    string str;
    void solve (int i, int j) {
        if (i<0 || j>str.length() || str[i]!=str[j])
            return;
        count++;
        solve(i-1, j+1);
    }
    int countSubstrings(string s) {
        count=0; str=s;
        for (int i=0; i<s.length(); i++) {
            solve(i, i); solve(i, i+1);
        }
        
        return count;
    }
};