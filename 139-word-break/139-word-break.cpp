class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> dict;
        for (auto s: wordDict)
            dict.insert(s);
        
        int n=s.length();
        vector<bool> dp (n+1, false);
        dp[0]=true;
        
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                if (dp[j]) {
                    string str = s.substr(j, i-j);
                    // cout << str << endl;
                    if (dict.find(str) != dict.end()) {
                        // cout << i << endl;
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};