static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lower == nums.size() || nums[lower] != target) {
            return {-1, -1};
        } else {
            return {lower, upper-1};
        }
    }
};