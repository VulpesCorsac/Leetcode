static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector < int > ans(nums.size(), 0);

        ans[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            ans[i] = nums[i-1] * ans[i-1];
        }

        int R = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= R;
            R *= nums[i];
        }

        return ans;
    }
};