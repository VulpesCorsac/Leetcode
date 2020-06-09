static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while (l < r) {
            if ((A[l]&1)) {
                swap(A[l], A[r]);
                --r;
            } else {
                ++l;
            }
        }

        return A;
    }
};