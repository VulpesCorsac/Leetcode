static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        const int N = s.size();
        int s_map[256] = {0};
        int t_map[256] = {0};
        
        for (int i = 0; i < N; ++i) {
            if (s_map[s[i]] != t_map[t[i]]) {
                return false;
            }
            
            s_map[s[i]] = t_map[t[i]] = i+1;
        }
        
        return true;
    }
};