static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool isHappy(int n) {
        unordered_set < int > used;
        while (n != 1) {
            if (used.count(n) > 0) {
                return false;
            }

            used.insert(n);

            int new_n = 0;
            while (n > 0) {
                int digit = n % 10;
                n /= 10;
                new_n += digit*digit;
            }
            
            n = new_n;
        }
        
        return true;
    }
};