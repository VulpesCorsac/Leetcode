static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < int > getRow(int rowIndex) {
        vector < int > ans = {1};

        for (int row = 1; row <= rowIndex; ++row) {
            vector < int > current_row(row+1, 1);

            for (int j = 1; j < row; ++j) {
                current_row[j] = ans[j-1] + ans[j];
            }

            ans = std::move(current_row);
        }

        return ans;
    }
};