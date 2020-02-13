static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    double myPow(double x, int n) {
        if (n > 0)
            return binpow(x, n);
        if (n < 0)
            return binpow(1/x, -n);
        return 1;
    }
    
    double binpow(double a, int n) {
        double res = 1;
        while (n) {
            if (n & 1)
                res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }
};