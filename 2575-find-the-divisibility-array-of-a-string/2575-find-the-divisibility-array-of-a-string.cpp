class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n=word.length();
        long long rem=0;
        vector<int> ans (n, 0);
        
        for (int i=0; i<n; i++) {
            rem *= 10;
            rem += word[i]-'0';
            rem = rem%m;
            ans[i] = !rem;
        }
        
        return ans;
    }
};