class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        
        int l=0, r=s.length()-1;
        
        while (l<r) {
            while (l<r && !iswalnum(s[l]))
                l++;
            while (r>l && !iswalnum(s[r]))
                r--;
            if (tolower(s[l]) != tolower(s[r])) {
                cout << s[l] << " " << s[r] << endl;
                return false;
            }
            l++; r--;
        }
                   
        return true;
    }
};