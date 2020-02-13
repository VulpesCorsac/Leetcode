static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (typed.length() == 0 && name.length() == 0) {
            return true;
        }
        if (typed.length() == 0 || name.length() == 0) {
            return false;
        }
        
        int n = 0;
        int t = 0;
        for (n = 0; n < name.length(); ) {
            if (name[n] != typed[t]) {
                return false;
            }
            
            auto next_n = advance(name, n);
            auto next_t = advance(typed, t);
            
            if (next_n - n > next_t - t) {
                return false;
            }
            
            n = next_n;
            t = next_t;
        }        
        
        return t == typed.size();
    }
    
    size_t advance(const string& s, size_t pos) {
        do {
            ++pos;
        } while (pos < s.length() && s[pos] == s[pos-1]);
        
        return pos;
    }
};