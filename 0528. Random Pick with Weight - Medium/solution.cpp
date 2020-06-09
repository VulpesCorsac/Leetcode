static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    Solution(vector < int > &w) {
        acc.reserve(w.size());
        for (int i : w) {
            total += i;
            acc.push_back(total);
        }
    }

    int pickIndex() {
        int r = rand() % total;
        auto itor = upper_bound(acc.begin(), acc.end(), r);
        return itor - acc.begin();
    }
private:
    vector < int > acc;
    int total = 0;
};