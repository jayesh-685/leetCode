class Solution {
public:
    
    void getKey (const string& s, string& key) {
        vector<int> v(26, 0);
        for (auto c: s)
            v[c-'a']++;
        
        for (auto x: v)
            key += to_string(x) + ",";
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> m;
        vector<vector<string>> ans;
        
        for (int i=0; i<strs.size(); i++) {
            string key="";
            getKey(strs[i], key);
            m[key].push_back(strs[i]);
        }
        
        for (auto it=m.begin(); it!=m.end(); it++)
            ans.push_back(it->second);
        
        return ans;
    }
};