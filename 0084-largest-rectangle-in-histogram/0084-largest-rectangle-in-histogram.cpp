class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n);
        stack <int> st1;
        
        for (int i=0; i<n; i++) {
            while (!st1.empty() && heights[st1.top()]>=heights[i])
                st1.pop();
            left[i] = st1.empty()? -1 : st1.top();
            st1.push(i);
        }
        
        vector<int> right(n);
        stack <int> st2;
        
        for (int i=n-1; i>=0; i--) {
            while (!st2.empty() && heights[st2.top()]>=heights[i])
                st2.pop();
            right[i] = st2.empty()? -1 : st2.top();
            st2.push(i);
        }
        
        int ans=0;
        
        for (int i=0; i<n; i++) {
            int l=left[i], r=right[i];
            if (r==-1)  r=n;
            
            ans = max(ans, (r-l-1)*heights[i]);
        }
        
        return ans;
    }
};