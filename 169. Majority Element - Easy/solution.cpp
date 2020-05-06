static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        
        for (const auto& item : nums) {
            if (cnt == 0) {
                ans = item;
            }
            
            cnt += (item == ans) ? +1 : -1;
        }
        
        return ans;
    }
};