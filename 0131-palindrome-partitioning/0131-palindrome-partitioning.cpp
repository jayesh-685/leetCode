class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome (string s) {
        string t = s;
        reverse(begin(s), end(s));
        return t==s;
    }
    void solve (string& s, int st, int en, vector<string>& v) {
        if (st==size(s)) {
            ans.push_back(v);
            return;
        }
        string temp="";
        for (int i=st; i<=en; i++) {
            temp += s[i];
            if (isPalindrome(temp)) {
                v.push_back(temp);
                solve(s, i+1, en, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=size(s);
        vector<string> v;
        solve(s, 0, n-1, v);

        return ans;
    }
};