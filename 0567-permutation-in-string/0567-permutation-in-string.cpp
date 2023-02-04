class Solution {
public:
    bool checkEqual (unordered_map<char,int>& m1, unordered_map<char,int>& m2) {
        if (size(m1) != size(m2))   return false;
        
        for (auto it=begin(m1); it!=end(m1); it++) {
            if (m2[it->first] != it->second)    return false;
        }
        
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        
        unordered_map <char, int> m1, m2;
        int k=size(s1), n=size(s2);
        if (k>n)    return false;
        for (int i=0; i<k; i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        
        if (checkEqual(m1, m2)) return true;
        
        for (int i=k; i<n; i++) {
            m2[s2[i]]++;
            m2[s2[i-k]]--;
            if (m2[s2[i-k]] == 0)   m2.erase(s2[i-k]);
            if (checkEqual(m1, m2)) return true;
        }
        
        return false;
    }
};