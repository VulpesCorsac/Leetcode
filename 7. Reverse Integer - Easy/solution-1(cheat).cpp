class Solution {
public:
    int reverse(int x) {
        long long xx = x;
        bool negative = (xx < 0);
        if (negative) {
            xx *= -1;
        }
        
        long long result = 0;
        while (xx > 0) {
            result = 10*result + xx%10;
            xx /= 10;
        }
        if (result > static_cast<long long>((1<<31) - 1)) {
            result = 0;
        }
        
        return negative ? -result : result; 
    }
};