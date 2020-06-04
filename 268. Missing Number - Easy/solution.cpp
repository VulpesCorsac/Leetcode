static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= i ^ nums[i];
        }
        
        return ans;
    }
};