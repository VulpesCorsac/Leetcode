static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int findTargetSumWays(vector < int >& nums, int S) {
        if (S > 1000) {
            return 0;
        }
        
        vector < int > dp(2001, 0);

        dp[f(+nums[0])] += 1;
        dp[f(-nums[0])] += 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            vector < int > next(2001, 0);
            
            for (int s = -1000; s <= 1000; ++s) {
                if (dp[f(s)] > 0) {
                    next[f(s+nums[i])] += dp[f(s)];
                    next[f(s-nums[i])] += dp[f(s)];                   
                }
            }
            
            dp = std::move(next);
        }
        
        return dp[f(S)];
    }
    
private:
    inline int f(int x) {
        return x + 1000;
    }
};