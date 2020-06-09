static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        while (r < s.length()) {
            while (r < s.length() && s[r] != ' ') {
                ++r;
            }

            cerr << l << " " << r << endl;
            reverse(s.begin() + l, s.begin() + r);
            ++r;
            l = r;
        }
        reverse(s.begin() + l, s.end());


        return s;
    }
};