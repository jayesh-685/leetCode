class Solution {
public:
//     solving using bs, but on range(values) and not on index
//     low is top left element which is the smallest element and high is bottom right element which is the largest element. We will calculte and mid and then find out how many elements are <= mid. if this is no is less than k then low=mid+1, if equal to k then return mid else high = mid-1
    int findRank(vector<vector<int>>& matrix, int x) {
        int count=0;
//         start from bottom left, if curr>k i-- else j++
        int n=matrix.size();
        int i=n-1, j=0;
        while (i>=0 && j<n) {
            if (matrix[i][j] > x) {
                i--;
            } else {
                count += i+1;   // if curr element is less than k and since elements are in sorted order so all elements row<i are also less than k
                j++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0], high=matrix[n-1][n-1];
        int ans;
        while (low<=high) {
            int mid = (low+high)/2;
            int rank = findRank(matrix, mid);
//             here we won't return when rank==mid because rank for mid and mid-1 might be equal for ex
//             1 3 7
//             5 10 12
//             6 10 15
//             here rank of 8 and 7 is same (5) but 7 is the correct answer and not 8
            if (rank >=k) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};