class NumMatrix {
public:
    // in the prefix sum matrix i,j represents the sum of matrix whose lower right corner is i,j
    // we calculate it by adding the sum of elements i,0 to i,j and matrix with lower right corner i-1,j
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=size(matrix), m=size(matrix[0]);
        sum.resize(n+1, vector<int>(m+1, 0));
        
        for (int i=1; i<=n; i++) {
            int psum=0;
            for (int j=1; j<=m; j++) {
                psum += matrix[i-1][j-1];
                sum[i][j] = psum + sum[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // sum1 = row2+1, col2+1
        // sum2 = row1, col2+1
        // sum3 = row2+1, col1
        
        int sum1 = sum[row2+1][col2+1], sum2=sum[row1][col2+1], sum3=sum[row2+1][col1], sum4=sum[row1][col1];
        
        return (sum1 - sum2 - sum3 + sum4);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */