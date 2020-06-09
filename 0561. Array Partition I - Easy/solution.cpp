static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size()/2; ++i) {
            result += nums[2*i];
        }

        return result;
    }
};