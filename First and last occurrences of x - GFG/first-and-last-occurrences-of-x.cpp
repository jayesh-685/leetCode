//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int i=0;
        
        while (i<n && arr[i] != x) i++;
        
        vector<int> ans;
        if (i==n) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        } else {
            ans.push_back(i);
        }
        
        i=n-1;
        while (i>=0 && arr[i]!=x) i--;
        ans.push_back(i);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends