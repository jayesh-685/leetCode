//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n=str1.length(), m=str2.length();
	    
	    vector<vector<int>> dp (n+1, vector<int>(m+1));
	    
	    for (int i=1; i<=n; i++) {
	        for (int j=1; j<=m; j++) {
	            dp[i][j] = str1[i-1]==str2[j-1] ? 1+dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    
	    int val = dp[n][m];
	    
	    return n-val + m-val; 
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends