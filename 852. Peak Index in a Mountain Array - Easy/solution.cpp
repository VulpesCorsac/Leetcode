static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return max_element(A.begin(), A.end()) - A.begin();
    }
};