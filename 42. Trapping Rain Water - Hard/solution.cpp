static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }

        auto water = height;

        int current_level = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (current_level < height[i]) {
                current_level = height[i];
            }

            water[i] = current_level;
        }

        current_level = 0;
        for (int i = height.size()-1; i >= 0; --i) {
            if (current_level < height[i]) {
                current_level = height[i];
            }

            water[i] = min(current_level, water[i]);
        }


        long long ans = 0;

        for (int i = 0; i < height.size(); ++i) {
            ans += water[i] - height[i];

        }

        return ans;
    }
};