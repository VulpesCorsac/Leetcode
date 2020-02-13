static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4; // n&3 is also suitable
    }
};