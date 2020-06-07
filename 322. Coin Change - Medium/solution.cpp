static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector < int > dp(amount+1, amount*2);
        dp[0] = 0;
        
        for (const auto& coin : coins) {
            for (auto i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};