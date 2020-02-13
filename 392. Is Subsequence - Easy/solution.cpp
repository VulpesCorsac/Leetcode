static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos_s = 0;
        int pos_t = 0;
        
        while (pos_s < s.length() && pos_t < t.length()) {
            if (s[pos_s] == t[pos_t]) {
                ++pos_s;
            }
            ++pos_t;
        }
        
        return pos_s == s.length();
    }
};