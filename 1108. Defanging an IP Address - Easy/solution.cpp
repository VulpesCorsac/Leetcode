static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";

        for (const auto& symbol: address) {
            if (symbol == '.') {
                result += "[.]";
            } else {
                result += symbol;
            }
        }

        return result;
    }
};