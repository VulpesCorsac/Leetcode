static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int dominantIndex(vector < int >& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int max1 = 0;
        int max2 = 0;
        int idx = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                idx = i;
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }

        return max1 >= 2 * max2 ? idx : -1;
    }
};