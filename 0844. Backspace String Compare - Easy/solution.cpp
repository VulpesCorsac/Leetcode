static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int s = S.length() - 1;
        int t = T.length() - 1;

        int skip_s = 0;
        int skip_t = 0;

        while (s >= 0 || t >= 0) {
            while (s >= 0) {
                if (S[s] == '#') {
                    --s;
                    ++skip_s;
                } else if (skip_s > 0 ) {
                    --skip_s;
                    --s;
                } else {
                    break;
                }
            }
            while (t >= 0) {
                if (T[t] == '#') {
                    --t;
                    ++skip_t;
                } else if (skip_t > 0 ) {
                    --skip_t;
                    --t;
                } else {
                    break;
                }
            }

            if (s >= 0 && t >= 0 && S[s] != T[t]) {
                return false;
            }

            if ((s >= 0) != (t >= 0)) {
                return false;
            }

            --s;
            --t;


        }

        return true;
    }
};