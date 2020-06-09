static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used_row    [9][9] = {0};
        int used_columns[9][9] = {0};
        int used_boxes  [9][9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;

                    if(used_row[i][num] || used_columns[j][num] || used_boxes[k][num]) {
                        return false;
                    }

                    used_row[i][num] = used_columns[j][num] = used_boxes[k][num] = 1;
                }
            }
        }

        return true;
    }
};