class Solution {
    public:
    bool valid(string str1, string str2, int k) {
        int len1 = str1.length(), len2 = str2.length();
        if (len1 % k > 0 || len2 % k > 0) {
            return false;
        } else {
            string base = str1.substr(0, k);
            int n1=str1.length()/k, n2=str2.length()/k;
            string s1="", s2="";
            for (int i=0; i<n1; i++)    s1 += base;
            for (int i=0; i<n2; i++)    s2 += base;
            return s1==str1 && s2==str2;
        }
    }
    
    
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; --i) {
            if (valid(str1, str2, i)) {
                return str1.substr(0, i);
            }
        }
        return "";
    }
};