class Solution {
public:
    string str;
    int solve (int i, int j) {
        int count=0;
        
        while (i>=0 && j<str.length() && str[i]==str[j]) {
            count++; i--; j++;
        }
        
        return count;
    }
    int countSubstrings(string s) {
        str = s;
        int ans=0;
        
        for (int i=0; i<s.length(); i++) {
            ans += solve(i, i); 
            ans += solve(i, i+1);
        }
        
        return ans;
    }
};