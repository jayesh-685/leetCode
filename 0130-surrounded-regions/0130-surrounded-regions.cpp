class Solution {
public:
    void fill (vector<vector<char>>& board, int i, int j, int n, int m) {
        if (i<0 || j<0 || i==n || j==m || board[i][j]=='X' || board[i][j]=='-')
            return;
        
        board[i][j] = '-';
        
        int ds[] = {-1, 0, 1, 0, -1};
        
        for (int k=0; k<4; k++) 
            fill(board, i+ds[k], j+ds[k+1], n, m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        
        for (int i=0; i<m; i++) {
            if (board[0][i]=='O')
                fill(board, 0, i, n, m);
            if (board[n-1][i]=='O')
                fill(board, n-1, i, n, m);
        }
        
        for (int i=0; i<n; i++) {
            if (board[i][0]=='O')
                fill(board, i, 0, n, m);
            if (board[i][m-1]=='O')
                fill(board, i, m-1, n, m);
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (board[i][j]=='O')
                    board[i][j]='X';
                else if (board[i][j]=='-')
                    board[i][j]='O';
            }
        }
    }
};