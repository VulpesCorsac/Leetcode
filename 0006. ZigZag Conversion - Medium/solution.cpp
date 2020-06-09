static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<vector<char>> str(numRows);
        for (auto& row: str) {
            row.reserve(s.length());
        }

        int current_column = 0;

        for (int i = 0; i < s.length(); ) {
            if (current_column % (numRows-1) == 0) {
                for (int j = 0; j < numRows; ++j) {
                    if (i < s.length()) {
                        str[j].push_back(s[i++]);
                    } else {
                        str[j].push_back(' ');
                    }
                }
                current_column = 0;
            } else {
                for (int j = 0; j < numRows; ++j) {
                    if (j == numRows-1-current_column) {
                        str[j].push_back(s[i++]);
                    } else {
                        str[j].push_back(' ');
                    }
                }
            }
            ++current_column;
        }

        string result;
        for (auto& row: str) {
            for (auto& symbol: row) {
                if (symbol != ' ') {
                    result += symbol;
                }
            }
        }

        return result;
    }
};