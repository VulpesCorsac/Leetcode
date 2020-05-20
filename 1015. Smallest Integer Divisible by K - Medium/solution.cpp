static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        int temp = 0;
        for (int res = 1; res <= K; ++res) {
            temp = (temp * 10 + 1) % K;
            if (!temp) {
                return res;
            }
        }
        return -1;
    }
};