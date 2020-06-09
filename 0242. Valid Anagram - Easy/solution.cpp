static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map < char, int > d;

        for (const auto& c : s) {
            ++d[c];
        }

        for (const auto& c : t) {
            --d[c];

            if (d[c] == 0) {
                d.erase(c);
            }
        }

        return d.empty();
    }
};