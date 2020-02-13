static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    bool checkPerfectNumber1(int num) {
        if (num == 6)
            return true;
        if (num == 28)
            return true;
        if (num == 496)
            return true;
        if (num == 8'128)
            return true;
        if (num == 3'3550'336)
            return true;

        return false;
    }

    bool checkPerfectNumber2(int num) {
        if (num < 6) {
            return false;
        }
        
        int sum = 1;
        
        for (int i = 2; i*i <= num; ++i) {
            if (num % i == 0) {
                sum += i + num / i;
            }
        }
        
        return sum == num;
    }

    bool checkPerfectNumber(int num) {
        return checkPerfectNumber2(num);
    }

};