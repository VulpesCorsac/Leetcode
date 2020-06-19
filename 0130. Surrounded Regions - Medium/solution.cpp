static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size();

        if (m == 0) {
            return;
        }

        const int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            if(board[i][0] == 'O') {
                DFS(board, i, 0, m, n);
            }
            if(board[i][n-1] == 'O') {
                DFS(board, i, n-1, m, n);
            }
        }


        for(int j = 0; j < n; ++j) {
            if(board[0][j] == 'O') {
                DFS(board, 0, j, m, n);
            }
            if(board[m-1][j] == 'O') {
                DFS(board, m-1, j, m, n);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') {
            return;
        }

        board[i][j] = 'S';

        DFS(board, i-1, j, m, n);
        DFS(board, i+1, j, m, n);
        DFS(board, i, j-1, m, n);
        DFS(board, i, j+1, m, n);
    }

};