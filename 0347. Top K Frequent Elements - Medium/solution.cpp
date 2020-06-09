static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < int > topKFrequent(vector < int > & nums, int K) {
        unordered_map < int, int > cnt;
        for (const auto& item : nums) {
            ++cnt[item];
        }

        priority_queue < pair < int, int > > q;

        for (const auto& [k, v] : cnt) {
            q.push({-v, k});

            if (q.size() > K) {
                q.pop();
            }
        }

        vector < int > ans;
        ans.reserve(q.size());
        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};