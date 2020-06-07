static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        if (m.empty() || m[0].empty()) {
            return m;
        }
        
        const int N = m.size();
        const int M = m[0].size();
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (m[i][j]) {
                    m[i][j] = 100000;
                    
                    if (i) {
                        m[i][j] = min(m[i][j], m[i-1][j] + 1);
                    }
                    if (j) {
                        m[i][j] = min(m[i][j], m[i][j-1] + 1);
                    }
                }
            }
        }
        
        for (int i = N-1; i >= 0; --i) {
            for (int j = M-1; j >= 0; --j) {
                if (m[i][j]) {
                    if (i < N-1) {
                        m[i][j] = min(m[i][j], m[i+1][j] + 1);
                    }
                    if (j < M-1) {
                        m[i][j] = min(m[i][j], m[i][j+1] + 1);
                    }
                }
            }
        }
                
        return m;
    }
};