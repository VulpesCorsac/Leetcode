static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }

        string  result;

        for (int i = 0; i < 1'000'000'000; ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j].length() < i+1) {
                    return result;
                }

                if (strs[j][i] != strs[0][i]) {
                    return result;
                }
            }

            result += strs[0][i];
        }

        return result;
    }
};