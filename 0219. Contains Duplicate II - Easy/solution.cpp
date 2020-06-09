static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map < int, int > m;

        for (int i = 0; i < nums.size(); ++i) {
            if (m[nums[i]] > 0 && i <= m[nums[i]]) {
                return true;
            }
            m[nums[i]] = i + k;
        }

        return false;
    }
};