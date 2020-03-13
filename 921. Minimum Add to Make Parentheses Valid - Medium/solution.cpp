static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int minAddToMakeValid(const string &S) {
        int ans = 0;
        
        int opened = 0;
        for (const auto &c : S) {
            if (c == '(') {
                ++opened;
            } else {
                --opened;
            }
            
            if (opened < 0) {
                ans -= opened;
                opened = 0;
            }
        }
        ans += opened;
        
        return ans;
    }
};