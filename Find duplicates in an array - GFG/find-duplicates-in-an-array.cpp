//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int> freq (n+1, 0);
        
        for (int i=0; i<n; i++) freq[arr[i]]++;
        
        vector<int> ans;
        for (int i=0; i<=n; i++) {
            if (freq[i] >= 2)    ans.push_back(i);
        }
        
        if (ans.size()) return ans;
        else            return {-1};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends