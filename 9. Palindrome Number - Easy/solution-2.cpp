static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;
        if (x < 0)
            return false;
        if (x % 10 == 0)
            return false;

        int tmp = x;
        long long revert = 0;

        while (tmp != 0) {
            revert *= 10;
            revert += tmp%10;
            tmp /= 10;
        }

        return revert==x;
    }
};