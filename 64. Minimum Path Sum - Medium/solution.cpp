static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int j = 0; j < grid[0].size(); ++j) {
            for (int i = 0; i < grid.size(); ++i) {
                if (j == 0) {
                   if (i == 0) {
                       /// pass
                   } else {
                       grid[i][j] += grid[i-1][j];
                   }
                } else {
                    if (i == 0) {
                        grid[i][j] += grid[i][j-1];
                    } else {
                        grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                    }
                }
            }
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};