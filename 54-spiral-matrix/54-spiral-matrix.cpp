class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=size(matrix), n=size(matrix[0]);
        int l=0, r=n-1, u=0, d=m-1;
        char dr='1';
        vector<int> ans;
        
        while (l<=r && u<=d) {
            switch (dr) {
                case '1': {
                    for (int i=l; i<=r; i++)
                        ans.push_back(matrix[u][i]);
                    u++; dr='2';
                    break;
                } case '2' : {
                    for (int i=u; i<=d; i++)
                        ans.push_back(matrix[i][r]);
                    r--; dr='3';
                    break;
                } case '3' : {
                    for (int i=r; i>=l; i--)
                        ans.push_back(matrix[d][i]);
                    d--; dr='4';
                    break;
                } case '4' : {
                    for (int i=d; i>=u; i--)
                        ans.push_back(matrix[i][l]);
                    l++; dr='1';
                    break;
                }
            }
        }
        
        return ans;
    }
};