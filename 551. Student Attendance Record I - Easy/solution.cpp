static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    bool checkRecord(string &s) {
        int absent = 0;
        int late = 0;
        
        for (const auto& c : s) {
            if (c == 'P') {
                late = 0;
            }
            if (c == 'A') {
                ++absent;
                late = 0;
                
                if (absent > 1) {
                    return false;
                }
            }
            if (c == 'L') {
                ++late;
                
                if (late > 2) {
                    return false;
                }
            }
        }
        
        return (absent <= 1 && late <= 2);
    }
};