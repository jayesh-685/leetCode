class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set <int> st;
        st.insert(0);
        int n=nums.size(), sum=accumulate(nums.begin(), nums.end(), 0);
        
        if (sum%2)
            return false;
        
        sum /= 2;
        
        for (int i=0; i<n; i++) {
            unordered_set <int> temp;
            for (auto it=st.begin(); it!=st.end(); it++) {
                if (*it==sum || (*it+nums[i]==sum))
                    return true;
                
                temp.insert(*it);
                temp.insert(*it + nums[i]);
            }
            
            st = temp;
        }
        
        return false;
    }
};