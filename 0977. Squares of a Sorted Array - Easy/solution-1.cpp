static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for_each(A.begin(), A.end(), [](int &i) {i *= i;});
        sort(A.begin(), A.end());

        return A;
    }
};