static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        return nums;
    }
};