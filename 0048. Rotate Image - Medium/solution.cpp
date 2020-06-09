static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; ++i) {
            int end = n-1 - i;
            for (int j = i; j < end; ++j) {
                int offset = j - i;
                int end_minus_offset = end-offset;

                int temp = matrix[i][j];
                matrix[i][j] = matrix[end_minus_offset][i];
                matrix[end_minus_offset][i] = matrix[end][end_minus_offset];
                matrix[end][end_minus_offset] = matrix[j][end];
                matrix[j][end] = temp;
            }
        }
    }
};