static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int prev = 0, cur = 0;
        for (int i = 0; i < s.length(); i ++) {
            char c = s[i];
            if (c == 'I') {
                cur = 1;
            } else if (c == 'V') {
                cur = 5;
            } else if (c == 'X') {
                cur = 10;
            } else if (c == 'L') {
                cur = 50;
            } else if (c == 'C') {
                cur = 100;
            } else if (c == 'D') {
                cur = 500;
            } else if (c == 'M') {
                cur = 1000;
            } else {
                return 0;
            }
            if (prev >= cur) {
                ans += prev;
                prev = cur;
            } else {
                prev = cur - prev;
            }
        }
        ans += prev;

        return ans;
    }
};