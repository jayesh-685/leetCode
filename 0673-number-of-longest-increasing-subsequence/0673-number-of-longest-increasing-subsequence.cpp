class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        // maintain 2 arrays, dp1[i] stores length of lis ending with nums[i], dp2[i] stores no of lis ending with nums[i].
        // if nums[j] < nums[i] dp1[j]+1 == dp1[i] then dp2[i]=dp2[j]. if dp1[j]==dp1[i] then dp2[i] += dp2[j]
        
        int n = arr.size();
    
    vector<int> dp(n,1);
    vector<int> ct(n,1);
    
    int maxi = 1;
    
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i] && dp[prev_index]+1>dp[i]){
                dp[i] = dp[prev_index]+1;
                //inherit
                ct[i] = ct[prev_index];
            }
            else if(arr[prev_index]<arr[i] && dp[prev_index]+1==dp[i]){
                //increase the count
                ct[i] = ct[i] + ct[prev_index];
            }
        }
         maxi = max(maxi,dp[i]);
    }
    
    int nos =0;
    
    for(int i=0; i<=n-1; i++){
       if(dp[i]==maxi) nos+=ct[i];
    }
    
    return nos;
    }
};