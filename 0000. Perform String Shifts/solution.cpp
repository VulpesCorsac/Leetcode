static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total_shift = 0;
        for (const auto& current_shift : shift) {
            total_shift += current_shift[0] == 0 ? current_shift[1] : -current_shift[1];
        }

        if (total_shift >= 0) {
            total_shift %= s.length();
        } else {
            total_shift *= -1;
            total_shift %= s.length();
            total_shift *= -1;
        }

        return makeShift(s, total_shift);
    }

    string makeShift(string s, int shift) {
        if (shift == 0) {
            return s;
        }

        string ans;
        if (shift > 0) {
            ans = s.substr(shift, s.length()) + s.substr(0, shift);
        } else {
            ans = s.substr(s.length()+shift, s.length()) + s.substr(0, s.length()+shift);
        }

        return ans;
    }
};