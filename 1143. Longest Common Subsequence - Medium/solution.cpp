static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int longestCommonSubsequence(const string& text1, const string& text2) {
        if (text1.empty() || text2.empty()) {
            return 0;
        }

        const int n = text1.length();
        const int m = text2.length();
//        vector < vector < int > > dp (n+1, vector < int > (m+1, 0));
        int dp[n+1][m+1];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i+1][j+1] = 1 + dp[i][j];
                } else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        return dp[n][m];
    }
};