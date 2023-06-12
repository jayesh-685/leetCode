class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0, j=1, n=size(nums);
        vector<string> ans;
        while (j<n) {
            while (j<n && nums[j] == nums[j-1]+1)  j++;
            if (j-i > 1)    ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
            else            ans.push_back(to_string(nums[i]));
            i=j; j++;
        }
        
        if (i!=n) {
            if (j-i > 1)    ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
            else            ans.push_back(to_string(nums[i]));
        }
        
        return ans;
    }
};