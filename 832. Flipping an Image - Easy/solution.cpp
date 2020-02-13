static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto &row: A) {
            reverse(row.begin(), row.end());
            
            for_each(row.begin(), row.end(), [](int& x){x^=1;});
        }
        
        return A;
    }
};