class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length(), l=0, maxL=0, maxF=0;
        vector<int> freq(26,0);
        
        for (int r=0; r<n; r++) {
            // cout << l << " " << r << endl;
            freq[s[r]-'A']++;
            maxF = max(maxF, freq[s[r]-'A']);
            
            while ( (r-l+1) - maxF > k) {
                freq[s[l]-'A']--;
                l++;
            }
            
            maxL = max(maxL, r-l+1);
        }
        
        return maxL;
    }
};