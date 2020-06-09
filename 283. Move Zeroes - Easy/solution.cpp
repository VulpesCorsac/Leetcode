static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int i){ return i != 0; });
    }
};