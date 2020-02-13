static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    int arrangeCoins(int n) {
        if (n < 2) {
            return n;
        }
        
        int row = 0;
        while (n >= 0) {
            ++row;
            n -= row;            
        }
        return row-1;
    }
};