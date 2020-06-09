static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length() || t.empty() || s.empty()) {
            return "";
        }

        unordered_map < char , int > t_map;
        unordered_map < char , int > window_map;

        for (const auto& item : t) {
            ++t_map[item];
        }

        int fitted = 0;
        int to_fit = t_map.size();

        int desirable_left = -1;
        int desirable_right = s.length();

        int left = 0;
        int right = -1;

        int len = s.length();

        while (right <= len && left < len) {
            while (right < len && fitted < to_fit) {
                ++right;
                ++window_map[s[right]];

                if (t_map.count(s[right]) > 0 && t_map[s[right]] == window_map[s[right]]) {
                    ++fitted;
                }
            }

            if (fitted == to_fit && right-left < desirable_right-desirable_left) {
                desirable_left = left;
                desirable_right = right;
            }

            if (t_map.count(s[left]) > 0 && t_map[s[left]] == window_map[s[left]]) {
                --fitted;
            }
            --window_map[s[left]];
            ++left;
        }

        if (desirable_left < 0) {
            return "";
        } else {
            return s.substr(desirable_left, desirable_right-desirable_left+1);
        }
    }
};