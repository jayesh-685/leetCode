class Solution {
public:
//     start from top right or bottom left
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int p=0, q=m-1;
        int curr=matrix[p][q];
        while (curr != target) {
            if (curr<target)
                p++;
            else if (curr>target)
                q--;
            if (p>=n || q<0)
                return false;
            curr = matrix[p][q];
        }
        return true;
    }
};