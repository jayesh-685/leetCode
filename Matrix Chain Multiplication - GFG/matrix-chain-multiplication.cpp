//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// in tabulation we solve smaller problems first which is f(n-2, n-1)
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int dp[N][N];
        
        for (int i=0; i<N; i++)
            dp[i][i]=0; // base case same as memo
            
        for (int i=N-1; i>=1; i--) {
            for (int j=i+1; j<N; j++) {
                // when we partition i represents left side and j represents right side j>i
                int ans=INT_MAX;
                for (int k=i; k<j; k++) {
                    ans = min(ans, dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
                dp[i][j]=ans;
            }
        }
        
        return dp[1][N-1];
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