static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> unique;
        for (const auto& item: A) {
            if (unique.count(item)) {
                return item;
            } else {
                unique.insert(item);
            }
        }

        return 0;
    }
};