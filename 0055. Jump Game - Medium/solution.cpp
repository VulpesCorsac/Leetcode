static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size() && i <= pos; ++i) {
            pos = max(pos, i + nums[i]);
        }
        return pos >= nums.size()-1;
    }
};