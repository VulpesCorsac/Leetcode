static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int temp = 0;

        for (const auto& item : nums) {
            if (item) {
                ++temp;
                ans = max(ans, temp);
            } else {
                temp = 0;
            }
        }

        return ans;
    }
};