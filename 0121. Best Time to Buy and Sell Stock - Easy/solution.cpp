static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int ans = 0;
        int min_price = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1]) {
                ans = max(ans, prices[i] - min_price);
            } else {
                min_price = min(min_price, prices[i]);
            }
        }

        return ans;
    }
};