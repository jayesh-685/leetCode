class Solution {
public:
//     consider a 4*3 matrix.
// to reach the destination you have to take 3 rights and 2 downs in some order.
//     so the answer is just the no of combinations of 3 rights and 2 downs which is n-1 + m-1 i.e n+m-2
//     we have to find out no of ways to choose n-1 right turns out of total of n+m-2 turns (or m-1 down turns out of total of n+m-2 turns)
//     answer is n+m-2 C n-1  or  n+m-2 C m-1
//     N C R is N!/R!*(N-R)!
//     using the trick 8 C 3 is 8*7*6/3*2*1
    int uniquePaths(int m, int n) {
        int N=m+n-2, R=m-1;
        double res=1;
        for (int i=1; i<=R; i++) {
            res = res * (N-R+i)/i;
        }
        
        return (int)res;
    }
};