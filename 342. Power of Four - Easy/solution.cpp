static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool isPowerOfFour(int num) {
        while (num > 0 && num % 4 == 0) {
            num /= 4;
        }

        return num == 1;
    }
};