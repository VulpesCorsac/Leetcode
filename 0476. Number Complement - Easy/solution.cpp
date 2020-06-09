static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask)
            mask <<= 1;
        return ~mask & ~num;
    }
};