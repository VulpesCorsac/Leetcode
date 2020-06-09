static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }

        int ans = 0;

        for (size_t p1 = 0; p1 < points.size(); ++p1) {
            int current = 0;
            int same = 1;
            unordered_map < double, int > slopes;
            for (size_t p2 = p1+1; p2 < points.size(); ++p2) {
                if (isSame(points[p1], points[p2])) {
                    ++same;
                    continue;
                }

                auto current_slope = slope(points[p1], points[p2]);
                ++slopes[current_slope];
                current = max(current, slopes[current_slope]);
            }
            ans = max(ans, current + same);
        }

        if (ans == 0) {
            ans = points.size();
        }

        return ans;
    }

    bool isSame(vector<int> &a, vector<int>&b) {
        return a[0] == b[0] && a[1] == b[1];
    }

    int GCD(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }

        return a;
    }

    double slope(vector<int> &a, vector<int>&b) {
        if(a[0] == b[0]) {
            return INT_MAX;
        }
        if(a[1] == b[1]) {
            return 0;
        }
        return 1.0 * (a[0]-b[0]) / (a[1]-b[1]);
    }
};