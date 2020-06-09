static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int firstUniqChar(const string& s) {
        if (s.empty()) {
            return -1;
        }

        int cnt[26] = {0};
        for (auto& c: s)
            ++cnt[c-'a'];
        for (int i = 0; i < s.length(); ++i) {
            if (cnt[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};