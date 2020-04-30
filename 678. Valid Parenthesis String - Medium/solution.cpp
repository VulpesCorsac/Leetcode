static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool checkValidString(const string &s) {
        int lo = 0;
        int hi = 0;
        
        for (const auto& c : s) {
            if (c == '(') {
                ++lo;
                ++hi;
            } else if (c == ')') {                
                --lo;
                --hi;
            } else {
                --lo;
                ++hi;
            }
            lo = max(lo, 0);
                        
            if (hi < 0) {
                return false;
            }
        }
        
        return lo <= 0 && 0 <= hi;
    }
};