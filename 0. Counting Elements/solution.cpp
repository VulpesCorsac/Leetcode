static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int countElements(vector<int>& arr) {
        vector < int > cnt(1010, 0);
        int ans = 0;
        
        for (auto& item : arr) {
            ++cnt[item];
        }
        
        for (int i = 0; i < 1000; ++i) {
            ans += cnt[i]*min(cnt[i+1], 1);
        }
        
        return ans;
    }
};