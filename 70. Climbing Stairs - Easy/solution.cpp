static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    int climbStairsCache(int n) {
        if (result.size() > n) {
            return result[n];
        } else {
            auto from = result.size();
            result.resize(n+1);
            
            for (int i = from; i < result.size(); ++i) {
                if (i < 2) {
                    result[i] = 1;
                } else {
                    result[i] = result[i-1] + result[i-2];
                }
            }
            
            return result[n];            
        }
    }
    
    vector < int > result;

    int climbStairs(int n) {
        int a[n+1];
        a[0] = 1;
        a[1] = 1;
        for(int i = 2; i <= n; i++) {
            a[i] = a[i-1] + a[i-2];
        }
        return a[n];
    }
};