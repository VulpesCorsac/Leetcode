class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int int_max = INT_MAX/10;
        int int_min = INT_MIN/10;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (result > int_max || (result == int_max && pop > 7)) {
                return 0;
            }
            if (result < int_min || (result == int_min && pop < -8)) {
                return 0;
            }
            result = result * 10 + pop;
        }
        return result;
    }
};