static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        auto parsed_pattern = parse_pattern(pattern);

        vector<string> result;
        for (auto& word: words) {
            if (match_pattern(parsed_pattern, word)) {
                result.push_back(word);
            }
        }

        return result;
    }

    vector<int> parse_pattern(const string& pattern) {
        vector<int> result(pattern.length(), -1);

        for (int i = 0; i < pattern.length(); ++i) {
            if (result[i] == -1) {
                result[i] = i;

                for (int j = i+1; j < pattern.length(); ++j) {
                    if (pattern[j] == pattern[i]) {
                        result[j] = i;
                    }
                }
            }
        }

        return result;
    }

    bool match_pattern(const vector<int>& parsed_pattern, const string& word) {
        return parsed_pattern == parse_pattern(word);
    }
};