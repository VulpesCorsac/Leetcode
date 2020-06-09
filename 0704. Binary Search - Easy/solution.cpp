static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int position = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (position < nums.size() && nums[position] == target) {
            return position;
        }

        return -1;
    }
};