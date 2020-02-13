static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        
        int first_mismatch = -1;
        int second_mismatch = -1;
        
        
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i]) {
                if (first_mismatch == -1) {
                    first_mismatch = i;
                } else if (second_mismatch == -1) {
                    second_mismatch = i;
                } else {
                    return false;
                }
            }
        }
        
        if (first_mismatch == -1 || second_mismatch == -1) {
            set < char > s(A.begin(), A.end());
            return s.size() < A.length();
        }
        
        return (A[first_mismatch] == B[second_mismatch] && B[first_mismatch] == A[second_mismatch]);
    }
};