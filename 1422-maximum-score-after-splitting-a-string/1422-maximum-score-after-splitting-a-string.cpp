class Solution {
public:
    int maxScore(string s) {
        int oc=0, zc=0;
        for (auto c: s) {
            oc += c=='1';
        }
        
        if (s[0] == '1')    oc -= 1;
        else                zc += 1;
        
        int ans = oc+zc;
        
        for (int i=1; i<s.length()-1; i++) {
            zc += s[i]=='0';
            oc -= s[i]=='1';
            ans = max(ans, oc+zc);
        }
        
        return ans;
        
        
    }
};