static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;

        int opened = 0;

        for (const auto& symbol: S) {
            if (symbol == '(') {
                if (opened) {
                    result += '(';
                }
                ++opened;
            } else {
                --opened;
                if (opened) {
                    result += ')';
                }
            }
        }

        return result;
    }
};