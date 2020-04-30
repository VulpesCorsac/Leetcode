static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (const auto& item : nums) {
            result ^= item;
        }
        
        return result;
    }
};