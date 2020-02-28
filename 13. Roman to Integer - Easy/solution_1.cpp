static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        
        bool substract = false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'M') {
                if (substract) {
                    ans += 900;
                    substract = false;
                } else {
                    ans += 1000;
                }
            } else if (s[i] == 'D') {
                if (substract) {
                    ans += 400;
                    substract = false;
                } else {
                    ans += 500;
                }
            } else if (s[i] == 'C') {
                if (substract) {
                    ans += 90;
                    substract = false;
                } else if (i+1 < s.length()) {
                    if (s[i+1] == 'M' || s[i+1] == 'D') {
                        substract = true;
                    } else {
                        ans += 100;
                    }
                } else {
                    ans += 100;
                }
            } else if (s[i] == 'L') {
                if (substract) {
                    ans += 40;
                    substract = false;                    
                } else {
                    ans += 50;
                }
            } else if (s[i] == 'X') {
                if (substract) {
                    ans += 9;
                    substract = false;
                } else if (i+1 < s.length()) {
                    if (s[i+1] == 'C' || s[i+1] == 'L') {
                        substract = true;
                    } else {
                        ans += 10;
                    }
                } else {
                    ans += 10;
                }
            } else if (s[i] == 'V') {
                if (substract) {
                    ans += 4;
                    substract = false;
                } else {
                    ans += 5;
                }
            } else if (s[i] == 'I') {
                if (i+1 < s.length()) {
                    if (s[i+1] == 'X' || s[i+1] == 'V') {
                        substract = true;
                    } else {
                        ans += 1;
                    }
                } else {
                    ans += 1;
                }
            } else {
                throw std::invalid_argument("");
            }
        }
        
        return ans;
    }
};