class Solution {
public:
    bool isVowel (char c) {
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool halvesAreAlike(string s) {
        int count=0;
        int n=s.length();
        for (int i=0; i<n; i++) {
            if (i<n/2 && isVowel(s[i]))
                count++;
            else if (i>=n/2 && isVowel(s[i]))
                count--;
        }
        
        return count==0;
    }
};