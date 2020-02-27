static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }
        
        int ans = 0;

        for (size_t p1 = 0; p1 < points.size(); ++p1) {
            for (size_t p2 = p1+1; p2 < points.size(); ++p2) {
                if (points[p2][0] == points[p1][0] && points[p2][1] == points[p1][1]) {
                    continue;
                }
                
                long long A = points[p1][1]-points[p2][1];
                long long B = points[p2][0]-points[p1][0];
                long long C = -A*points[p1][0] - B*points[p1][1];
                
                int current = 0;
                
                for (int p = 0; p < points.size(); ++p) {
                    if (A*points[p][0] + B*points[p][1] + C == 0) {
                        if (p < p1) {
                            break;
                        } else {
                            ++current;
                        }
                    }
                }
                
                ans = max(ans, current);
            }
        }
        
        if (ans == 0) {
            ans = points.size();
        }
        
        return ans;
    }
};