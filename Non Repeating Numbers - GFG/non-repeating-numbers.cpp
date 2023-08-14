//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int ans=0;
        for (auto& num: nums) {
            ans = ans^num;
        }
        
        int i=0;
        for (i=0; i<32; i++) {
            if ((1<<i)&ans) break;
        }
        
        int st1=0, st2=0;
        for (auto& num: nums) {
            if ((1<<i)&num) {
                st1 = st1^num;
            } else {
                st2 = st2^num;
            }
        }
        
        vector<int> v {st1, st2};
        sort(begin(v), end(v));
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends