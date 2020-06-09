static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }

        static vector < int > cntPerfectSquares({0});

        if (cntPerfectSquares.size() < n) {
            cntPerfectSquares.reserve(n);
        }

        while (cntPerfectSquares.size() <= n) {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++) {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }

            cntPerfectSquares.push_back(cntSquares);
        }

        return cntPerfectSquares[n];
    }
};