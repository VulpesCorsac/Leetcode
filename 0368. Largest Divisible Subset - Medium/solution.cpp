static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < int > largestDivisibleSubset(vector < int >& nums) {
        const int n = nums.size();
        if(n < 2) {
            return nums;
        }

        sort(nums.begin(), nums.end());

        vector < int > dp(n, 1);
        int max_elements = INT_MIN;

        for(int i = 1; i < n; ++i) {
            for(int j = i-1; j >= 0; --j) {
                if(nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            max_elements = max(max_elements, dp[i]);
        }

        vector < int > ans;

        for(int i = n-1; i >= 0; --i) {
            if(dp[i] == max_elements) {
                ans.push_back(nums[i]);
                --max_elements;
            }
        }

        return ans;
    }
};