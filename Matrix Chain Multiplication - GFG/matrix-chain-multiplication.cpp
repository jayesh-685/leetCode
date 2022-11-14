//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// it takes O(n) time to calculate f(i, j) and there are n^2 possible valued for i and j so final time complexity is O(n^3)
    int f (int arr[], int i, int j, vector<vector<int>>& dp) {
        if(i == j)
            return 0;
        
        if (dp[i][j])
            return dp[i][j];
        int mini = INT_MAX;
        
        // partioning loop
        for(int k = i; k<= j-1; k++){
            
            int ans = f(arr,i,k, dp) + f(arr, k+1,j, dp) + arr[i-1]*arr[k]*arr[j];
            
            mini = min(mini,ans);
            
        }
        
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp (N, vector<int>(N));
        return f(arr, 1, N-1, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends