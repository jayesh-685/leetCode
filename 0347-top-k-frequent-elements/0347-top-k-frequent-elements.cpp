class Solution {
public:
//     modification of bucket sort
//     in bucket store you create a array and store frequency of each element 
//     here we will create a array of size n+1 and arr[i] will store list of elements with freq = i
//     so we will start from last and print k elements
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        for (auto n: nums)
            mp[n]++;
        
        vector <vector<int>> bucket (nums.size()+1);
        
        for (auto it: mp) {
            bucket[it.second].push_back(it.first);
        }
        
        vector<int> ans;
        for (int i=nums.size(); i>0; i--) {
            if (bucket[i].size()) {
                for (int j=0; j<bucket[i].size() && ans.size()<k; j++)
                    ans.push_back(bucket[i][j]);
            }
        }
        
        return ans;
    }
};