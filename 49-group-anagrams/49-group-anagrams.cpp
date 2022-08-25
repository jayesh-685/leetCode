class Solution {
public:
    // sort the strings then store them in map where key is the sorted string and value is the anagrams like aet: {eat, tea, ate}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map <string, vector<string>> m;
        
        for (int i=0; i<strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            m[str].push_back(strs[i]);
        }
        
        for(auto i = m.begin(); i != m.end(); i++)
            ans.push_back(i -> second);
        
        return ans;
    }
};