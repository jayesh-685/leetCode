class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n=size(nums), i=(n-1)/2, j=n-1, ans=0, temp=i;
        
        while (i>=0 && j>temp) {
            if (nums[i]*2 <= nums[j]) {
                ans += 2;
                j--;
            }
            i--;
        }
        
        return ans;
    }
};