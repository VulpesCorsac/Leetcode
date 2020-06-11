static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (const auto& item: nums) {
            if (item == 0) {
                ++zeros;
            } else if (item == 1) {
                ++ones;
            } else {
                ++twos;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i < zeros) {
                nums[i] = 0;
            } else if (i < zeros + ones) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }

		return;
    }
};