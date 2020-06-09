static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        int max_sqrt = static_cast<int>(sqrt(INT_MAX));

        int left = 0;
        int right = x/2+1;
        while (right-left > 1) {
            int mid = (left + right)/2;
            if (mid > max_sqrt || mid*mid > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};