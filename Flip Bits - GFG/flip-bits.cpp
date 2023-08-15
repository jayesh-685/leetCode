//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int zeroCount=0, oneCount=0;
        for (int i=0; i<n; i++) {
            zeroCount += a[i]==0;
            oneCount += a[i]==1;
        }
        
        int cntr=0, maxi=0;
        for (int i=0; i<n; i++) {
            if (a[i]==0) {
                cntr++;
                maxi=max(maxi, cntr);
            } else {
                if (cntr > 0)   cntr--;
            }
        }
        
        int ans=0;
        ans = max(ans, oneCount+maxi);
        
        // cntr=0, maxi=0;
        // for (int i=0; i<n; i++) {
        //     if (a[i]==1) {
        //         cntr++;
        //         maxi=max(maxi, cntr);
        //     } else {
        //         if (cntr > 0)   cntr--;
        //     }
        // }
        
        // ans = max(ans, zeroCount+maxi);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends