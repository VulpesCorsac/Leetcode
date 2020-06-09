static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int k = 1; k < 4; ++k) {
            for (int i = 0; i < A.size() - k; ++i) {
                if (A[i] == A[i + k]) {
                    return A[i];
                }
            }
        }

        return 0;
    }
};