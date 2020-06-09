static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n-1));
    }
};