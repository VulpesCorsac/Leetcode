static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int freq[101] = {0};
        
        for (const auto& item : heights) {
            ++freq[item];
        }
        
        int ans = 0;
        int height = 0;
        for (const auto& item : heights) {
            while (!freq[height]) {
                ++height;
            }
            
            if (height != item) {
                ++ans;
            }
            
            --freq[height];
        }
        
        return ans;
    }
};