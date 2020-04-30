static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map < int, int > count;
        
        int ans = 0, current_count = 0;
        count[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            current_count += nums[i] == 1 ? 1 : -1;
            
            if (count.count(current_count)){
                ans = max(ans, i - count[current_count]);
            }  else {
                count[current_count] = i;
            }
        }
        
        return ans;
    }
};