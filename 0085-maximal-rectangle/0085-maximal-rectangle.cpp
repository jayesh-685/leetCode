class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0, n=heights.size();
        stack <int> st;
        
        for (int i=0; i<=n; i++) {
            while (!st.empty() && (i==n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()]; st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                ans = max(ans, height*width);
            }
            st.push(i);
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size(), m=matrix[0].size();
        vector<int> hist(m, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (matrix[i][j]=='1')
                    hist[j]++;
                else
                    hist[j]=0;
            }
            ans = max(ans, largestRectangleArea(hist));
        }
        
        return ans;
    }
};