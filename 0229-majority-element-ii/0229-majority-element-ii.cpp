class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size(), count=floor(n/3);
        unordered_map<int, int> mp;

        vector<int> ans;
        for (auto x: arr) {
            mp[x]++;
            if (mp[x]==count+1)
                ans.push_back(x);
        }

        return ans;
    }
};