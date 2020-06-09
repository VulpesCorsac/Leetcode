static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            ans += n & 1;
            n >>= 1;
        }

        return ans;
    }
};