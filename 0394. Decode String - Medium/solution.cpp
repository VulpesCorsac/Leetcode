static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(s, pos);
    }

    string helper(const string& s, int& pos) {
        int number = 0;
        string current_string = "";

        for (; pos < s.length(); ++pos) {
            auto symbol = s[pos];
            if (symbol == '[') {
                string result = helper(s, ++pos);
                for (; number > 0; --number) {
                    current_string += result;
                }
            } else if (symbol == ']') {
                return current_string;
            } else if (symbol >= '0' && symbol <= '9') {
                number = number * 10 + symbol - '0';
            } else {
                current_string += symbol;
            }
        }

        return current_string;
    }
};