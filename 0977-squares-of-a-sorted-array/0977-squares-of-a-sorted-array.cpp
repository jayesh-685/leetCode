class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n=size(nums);
        vector<int> v(n);
        
        int i=0, j=n-1, k=n-1;
        
        while (i<=j) {
            if (abs(nums[i]) < abs(nums[j])) {
                v[k] = nums[j]*nums[j];
                j--;
            } else {
                v[k] = nums[i]*nums[i];
                i++;
            }
            
            k--;
        }
        
        return v;
    }
};