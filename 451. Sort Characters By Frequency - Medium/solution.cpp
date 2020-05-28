static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string frequencySort(string s) {
        vector < pair < int, char > > count(128);
        for(const auto &c: s) {
            count[c - ' '].first++;
            count[c - ' '].second = c;
        }

        sort(rbegin(count), rend(count));

        return accumulate(begin(count), end(count), string(), [](auto &s, const auto &p) {
                                                                  return move(s) + string(p.first, p.second);
                                                              }
                         );
    }
};