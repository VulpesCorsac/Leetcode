static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        stable_sort(A.begin(), A.end(), [](int i, int j){return (i%2 < j%2);});
        return A;
    }
};