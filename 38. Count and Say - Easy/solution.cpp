static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";

        while (--n) {
            string cur = "";
            for (int i = 0; i < res.length(); ++i) {
                int cnt = 1;
                while (i+1 < res.length() && res[i] == res[i+1]) {
                    ++i;
                    ++cnt;
                }

                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }

        return res;
    }
};