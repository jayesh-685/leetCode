class Solution {
public:
    int partitionString(string s) {
        int count=1;
        int v[26];
        memset(v, 0, sizeof(v));
        
        for (int i=0; i<s.length(); i++) {
            if (v[s[i]-'a']) {
                count++;
                memset(v, 0, sizeof(v));
            }
            v[s[i]-'a']=1;
        }
        
        return count;
    }
};