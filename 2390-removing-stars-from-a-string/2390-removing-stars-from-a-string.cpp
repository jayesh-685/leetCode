class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='*')  st.pop();
            else            st.push(s[i]);
        }
        
        string ans;
        while (!st.empty()) {
            ans += st.top(); st.pop();
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};