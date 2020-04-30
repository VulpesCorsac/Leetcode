static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int maximalSquare(vector < vector < char > >& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        int dp[n+1][m+1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }
        
        int max_size = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                    max_size = max(max_size, dp[i][j]);
                }
            }
        }
        
        return max_size*max_size;
    }
};