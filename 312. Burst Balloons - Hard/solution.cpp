static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        vector < vector < int > > dp(nums.size(), vector < int > (nums.size(), 0));
        
        for (int L = nums.size()-1; L >= 0; --L) {
            for (int R = L; R < nums.size(); ++R) {
                for (int i = L; i <= R; ++i) {
                    dp[L][R] = max(dp[L][R], 
                                   (L > 0 ? nums[L-1] : 1) * nums[i] * (R == nums.size()-1 ? 1 : nums[R+1])
                                   + (L <= i-1 ? dp[L][i-1] : 0)
                                   + (R >= i+1 ? dp[i+1][R] : 0)
                                  );
                }
            }
        }
        
        return dp[0][nums.size()-1];
    }
};