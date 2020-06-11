static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < string > generateParenthesis(int n) {
        back_track(n);

        return ans;
    }

    void back_track(int n, string s = "", int opened = 0, int closed = 0) {
        if (s.length() == 2*n && opened == closed) {
            ans.push_back(s);

            return;
        }

        if (opened < n) {
            back_track(n, s + '(', opened+1, closed);
        }
        if (closed < opened) {
            back_track(n, s + ')', opened, closed+1);
        }
    }

    vector < string > ans;
};