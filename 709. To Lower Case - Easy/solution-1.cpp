static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        return str;
    }
};