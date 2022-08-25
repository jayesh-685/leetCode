class Solution {
public:
    // sort the strings then store them in map where key is the sorted string and value is the anagrams like aet: {eat, tea, ate}
    
    void getFreq (string& s, vector<int>& v) {
        for (int i=0; i<s.length(); i++) {
            v[s[i]-'a']++;
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map <vector<int>, vector<string>> m;
        
        for (int i=0; i<strs.size(); i++) {
            vector<int> v (26, 0);
            getFreq (strs[i], v);
            m[v].push_back(strs[i]);
        }
        
        for(auto i = m.begin(); i != m.end(); i++)
            ans.push_back(i -> second);
        
        return ans;
    }
};