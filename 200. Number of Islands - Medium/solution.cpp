static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    void dfs(int i, int j, vector < vector < char > >& grid) {
        grid[i][j] = '2';
        
        int di[4] = {1, -1, 0, 0};
        int dj[4] = {0, 0, 1, -1};
        
        for (int d = 0; d < 4; ++d) {
            if (i+di[d] >= 0 && i+di[d] < grid.size() &&
                j+dj[d] >= 0 && j+dj[d] < grid[i+di[d]].size() &&
                grid[i+di[d]][j+dj[d]] == '1') {
                dfs(i+di[d], j+dj[d], grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++islands;
                    dfs(i, j, grid);
                }
            }
        }
        
        return islands;
    }
};