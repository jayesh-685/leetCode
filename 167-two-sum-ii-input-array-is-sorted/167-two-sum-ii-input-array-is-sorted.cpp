class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size(), left=0, right=n-1;
        int sum=numbers[left]+numbers[right];
        
        while (sum!=target) {
            if (sum>target)
                right--;
            if (sum<target)
                left++;
            
            sum=numbers[left]+numbers[right];
        }
        
        vector<int> ans = {left+1, right+1};
        return ans;
    }
};