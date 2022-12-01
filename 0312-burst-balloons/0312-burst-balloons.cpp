class Solution {
public:
//     int solve (vector<int> nums) {
//         if (nums.size()==1)
//             return nums[0];
        
//         int maxi = INT_MIN;
//         for (int i=0; i<nums.size(); i++) {
//             int ans = nums[i] * (i-1<0 ? 1 : nums[i-1]) * (i+1>=nums.size() ? 1 : nums[i+1]);
//             int temp=nums[i];
//             nums.erase(nums.begin()+i);
//             ans += solve(nums);
//             maxi = max(maxi, ans);
//             nums.insert(nums.begin()+i, temp);
//         }
        
//         return maxi;
//     }
    
    /*
    For a DP solution to exist, we need to define the subproblems. Let's define the problem first as:

solve(nums, i, j)
by which I mean that we need to burst balloons starting from index i to index j. At the beginning, they'll be 0, nums.size() -1 respectively. Let's suppose we burst the kth balloon in the first chance. We will get nums[k-1] * nums[k] * nums[k+1] coins. Now let's define the subproblems as:

solve(nums, i, k - 1) , solve(nums, k + 1, j)
As the balloon k is already burst, we solve the subproblems from i to k -1 and k + 1 to j. But wait, what's going wrong here? The subproblem solve(nums, i, k - 1) and solve(nums, k + 1, j) are not independent since after bursting kth balloon, balloon k - 1 and k + 1 have become adjacent and they will need each other in order to calculate the profit.

So, as we saw that if we choose the kth balloon to be the first one to be burst, we can't make the subproblems independent. Let's try the other way round. We choose the kth balloon as the last one to be burst. Now the subproblems will become independent since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer. (Try it out using pen and paper).

Now for each k starting from i to j, we choose the kth balloon to be the last one to be burst and calculate the profit by solving the subproblems recursively. Whichever choice of k gives us the best answer, we store it and return.
Important point to be noted here is that the balloons in the range (i, k - 1) and (k + 1, j) will be burst BEFORE kth balloon. So, when we burst the kth balloon, the profit will be nums[i - 1] * nums[k] * nums[j + 1] PROVIDED that index i - 1 and j + 1 are valid.
    */
    
    int solve (vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        
        if (i>j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int maxi = INT_MIN;
        for (int k=i; k<=j; k++) {
            int ans = (nums[i-1] * nums[k] * nums[j+1]) + solve(nums, i, k-1, dp) + solve(nums, k+1, j, dp); 
            maxi = max(maxi, ans);
        }
        
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n=nums.size();
        vector<vector<int>> dp (n, vector<int>(n, -1));
        return solve(nums, 1, nums.size()-2, dp);
    }
};