static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < int > countBits(int num) {
        vector < int > ret(num+1, 0);
        
        for (int i = 1; i <= num; ++i) {
            ret[i] = ret[i & (i-1)] + 1;
        }
        
        return ret;
    }
};