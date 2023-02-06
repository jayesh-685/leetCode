class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans (2*n);
        int p1=0, p2=n, i=0;
        while (p2<2*n) {
            ans[i++] = nums[p1++];
            ans[i++] = nums[p2++];
        }
        
        return ans;
    }
};