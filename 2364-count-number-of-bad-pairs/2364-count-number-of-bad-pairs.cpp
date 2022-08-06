class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long ans = n*(n-1)/2;
        
        unordered_map <int, int> m;
        for (int i=0; i<n; i++) {
            int key=nums[i]-i;
            if (m.find(key) == m.end())
                m[key]=0;
            else
                m[key]++;
        }
        
        for (auto it: m) 
            cout << it.first << " " << it.second << endl;
        
        
        for (int i=0; i<n; i++) {
            int key=nums[i]-i;
            ans -= m[key];
            m[key]--;
        }
        
        return ans;
    }
};