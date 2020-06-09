static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector < vector < int > > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector < int > res;

        int N = matrix.size();
        if (!N) {
            return res;
        }
        int M = matrix[0].size();
        if (!M) {
            return res;
        }

        vector < int > nSteps{M, N-1};

        int dir_idx = 0;
        int row = 0;
        int column = -1;
        while (nSteps[dir_idx%2]) {
            for (int i = 0; i < nSteps[dir_idx%2]; ++i) {
                row    += dirs[dir_idx][0];
                column += dirs[dir_idx][1];
                res.push_back(matrix[row][column]);
            }
            nSteps[dir_idx%2]--;
            dir_idx = (dir_idx + 1) % 4;
        }

        return res;
    }
};