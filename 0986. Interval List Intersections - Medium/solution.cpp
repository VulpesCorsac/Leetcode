static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector <vector < int > > intervalIntersection(vector < vector < int > >& A, vector < vector < int > >& B) {
        vector < vector < int > > result;

        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            auto lo = max(A[i][0], B[j][0]);
            auto hi = min(A[i][1], B[j][1]);

            if (lo <= hi) {
                result.push_back({lo, hi});
            }

            if (A[i][1] < B[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }

        return result;
    }
};