static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long _dividend = dividend;
        long long _divisor = divisor;

        long long result = _dividend / _divisor;

        if (result > INT_MAX) {
            result = INT_MAX;
        }
        if (result < INT_MIN) {
            result = INT_MAX;
        }

        return static_cast<int>(result);
    }
};