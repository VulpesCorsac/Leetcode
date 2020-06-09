static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int max_area = r * min(height[l], height[r]);

        while (r > l) {
            max_area = max(max_area, (r-l)*min(height[l], height[r]));

            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return max_area;
    }
};