static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector < int > ans(prices.size(), 0);

        for (int i = 0; i < prices.size(); ++i) {
            int k = -1;
            for (int j = i+1; j < prices.size(); ++j) {
                if (prices[j] <= prices[i]) {
                    k = j;
                    break;
                }
            }

            ans[i] = prices[i];
            if (k > 0) {
                ans[i] -= prices[k];
            }
        }

        return ans;
    }
};