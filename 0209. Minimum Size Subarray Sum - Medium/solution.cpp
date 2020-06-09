static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        int ans  = INT_MAX;
        int left = 0;
        int sum  = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i+1-left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};