static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int prev = 0;
        int curr = 0;

        for (const auto& item : nums) {
            auto tmp = prev;
            prev = max(curr + item, prev);
            curr = tmp;
        }

        return prev;
    }
};