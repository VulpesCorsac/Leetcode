static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int result = 0;
        
        for (int i = 0; i < A[0].length(); ++i) {
            for (int j = 0; j < A.size()-1; ++j) {
                if (A[j][i] > A[j+1][i]) {
                    ++result;
                    break;
                }
            }
        }
        
        return result;
    }
};