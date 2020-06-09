static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        bool prime[n+1];
        memset(prime, true, sizeof(prime));
        int res = 1;

        for(int i = 3; i < n; i += 2) {
            if(prime[i] == true) {
                ++res;
                if (i <= sqrt(n)) {
                    for(int j = i*i; j <= n; j += i) {
                        prime[j] = false;
                    }
                }
            }
        }

        return res;
    }
};