typedef pair<int, int> pi;
class Solution {
public:
//     worst case is still O(nlogn) in case all elements are unique
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> m;
        for (auto c: nums) {
            m[c]++;
        }
        
        priority_queue <pi, vector<pi>, greater<pi>> pq;
        for (auto p: m) {
            pq.push({p.second, p.first});
            if (pq.size() > k)  pq.pop();
        }
        
        vector<int> ans;
        while (!pq.empty()) {
            auto [x, y] = pq.top(); pq.pop();
            ans.push_back(y);
        }
        
        return ans;
    }
};