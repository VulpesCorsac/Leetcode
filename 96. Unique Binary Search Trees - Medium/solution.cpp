static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int numTrees(int n) {
        if (n >= dp.size() || dp[n] == 0) {
            if (n >= dp.size()) {
                dp.resize(n+1, 0);
            }
            
            for (int root = 1; root <= n; root++) {
                dp[n] += numTrees(n-root) * numTrees(root-1);
            }
        }
        
        return dp[n];
    }
    
private:
    vector < int > dp = {1, 1};
};