static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        
        vector<int> prefrix_min(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            prefrix_min[i] = min(prefrix_min[i-1], nums[i]);
        }
        
        stack<int> st;
        
        for (int i = nums.size()-1; i >= 0; --i) {
            if (nums[i] > prefrix_min[i]) {
                while (!st.empty() && st.top() <= prefrix_min[i]) {
                    st.pop();
                }
                
                if (!st.empty()) {
                    if (st.top() < nums[i]) {
                        return true;
                    }
                }
                
                st.push(nums[i]);
            }
        }
        
        return false;
    }
};