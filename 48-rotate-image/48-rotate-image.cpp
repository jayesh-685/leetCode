class Solution {
public:
    //     transpose + reverse is also magic

    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        
        for (auto& r: matrix)
            reverse(r.begin(), r.end());
    }
};