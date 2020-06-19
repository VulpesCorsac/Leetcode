static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < int > houses;
    map < pair < int, int > , int > cache_cost;
    map < pair < int, int > , int > cache_dfs;

    int minDistance(vector<int>& in, int k) {
        houses = std::move(in);
        sort(houses.begin(), houses.end());

        return dfs(0, k);
    }

    int getCost(int start, int end) {
        if (cache_cost.count({start, end})) {
            return cache_cost[{start, end}];
        }

        int m = houses[(end + start) / 2];
        if ((end - start) % 2 == 0) {
            m = (houses[(end + start) / 2] + houses[(end + start + 1) / 2]) / 2;
        }

        int ans = 0;
        for (int i = start; i <= end; ++i) {
            ans += abs(houses[i] - m);
        }

        return cache_cost[{start, end}] = ans;
    }

    int dfs(int position, int k) {
        if (cache_dfs.count({position, k})) {
            return cache_dfs[{position, k}];
        }

        if (position + k >= houses.size()) {
            return 0;
        }
        if (k == 0) {
            return 1000000000;
        }

        int ans = INT_MAX;
        for (int i = position; i < houses.size(); ++i) {
            ans = min(ans, getCost(position, i) + dfs(i+1, k-1));
        }

        return cache_dfs[{position, k}] = ans;
    }
};