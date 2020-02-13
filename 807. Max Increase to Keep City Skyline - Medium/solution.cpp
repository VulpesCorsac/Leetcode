class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int result = 0;
        
        int N = grid.size();
        vector<int> top(N, 0);
        vector<int> left(N, 0);
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                left[i] = max(left[i], grid[i][j]);
                top[j] = max(top[j], grid[i][j]);
            }
        }
                
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                result += min(top[i], left[j]) - grid[i][j];
            }
        }
        
        return result;
    }
};