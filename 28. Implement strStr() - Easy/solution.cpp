static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = 0;

        result = haystack.find(needle);

        if (result == string::npos) {
            result = -1;
        }

        return result;
    }
};