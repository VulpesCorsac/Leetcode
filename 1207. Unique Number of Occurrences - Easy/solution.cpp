static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> occurrences;
        set<int> unique_occurrences;

        for (const auto& item: arr) {
            ++occurrences[item];
        }

        for (const auto& item: occurrences) {
            unique_occurrences.insert(item.second);
        }

        return unique_occurrences.size() == occurrences.size();
    }
};