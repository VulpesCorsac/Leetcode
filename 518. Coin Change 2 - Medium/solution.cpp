static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector < int > cnt(amount+1, 0);
        cnt[0] = 1;
        
        for (const auto& coin : coins) {
            for (auto i = coin; i <= amount; ++i) {
                cnt[i] += cnt[i-coin];
            }
        }
        
        return cnt[amount];
    }
};