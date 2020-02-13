static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        
        while (left <= right) {
            long int mid = left + (right - left) / 2;
            
            if (mid*mid == num) {
                return true;
            }
            
            if (mid*mid < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};