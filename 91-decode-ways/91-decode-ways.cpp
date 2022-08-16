class Solution {
public:
    int numDecodings(string s) {
        vector <int> dp (s.length()+1, 0);
        dp[s.length()] = 1;
        for (int i=s.length()-1; i>=0; i--) {
            int l1=0;
            if (s[i] != '0')
                l1 = dp[i+1];
            int l2=0;
            if (i<s.length()-1) {
                string temp = s.substr(i,2);
                if (temp>="10" && temp<="26")
                    l2 = dp[i+2];
            }
            dp[i] = l1+l2;
            cout << i << " " << dp[i] << endl;
        }
        
        return dp[0];
    }
};