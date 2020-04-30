static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        
        unordered_map < int, int > sums;
        int cnt = 0, sum = 0;
        
        sums[0] = 1;
        for (const auto& item : nums) {
            sum += item;
            if (sums.count(sum-k)) {
                cnt += sums[sum-k];
            }
            ++sums[sum];
        }
        
        return cnt;
    }
};