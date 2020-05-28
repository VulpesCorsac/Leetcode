static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int countSquares(vector < vector < int > > & matrix) {
        const int n = matrix.size();
        const int m = matrix[0].size();
        
        int dp[2][m];
        int result = 0;
        
        int c = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[c][j] = matrix[i][j];
                if (i != 0 && j != 0 && dp[c][j]) {
                    dp[c][j] += min(min(dp[c^1][j], dp[c^1][j-1]), dp[c][j-1]);
                }
                
                result += dp[c][j];
            }
            
            c ^= 1;
        }
        
        return result;
    }
};