class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1=word1.length(), n2=word2.length();
        int p1=0, p2=0;
        for (int i=0; i<max(n1, n2); i++) {
            if (p1<n1) {
                ans += word1[p1];
                p1++;
            }
            if (p2<n2) {
                ans += word2[p2];
                p2++;
            }
        }
        
        return ans;
    }
};