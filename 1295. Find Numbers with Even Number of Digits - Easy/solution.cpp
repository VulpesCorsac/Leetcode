static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(const auto& n : nums) {
            if((10 <= n && n <= 99) || (1000 <= n && n <= 9999 ) || (n == 100000)) {
               ++count;
            }
        }
        return count;
    }
};