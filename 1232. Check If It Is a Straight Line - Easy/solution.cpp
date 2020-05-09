static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 3) {
            return true;
        }
        
        int A = coordinates[0][1]-coordinates[1][1];
        int B = coordinates[1][0]-coordinates[0][0];
        int C = - A*coordinates[0][0] - B*coordinates[0][1];
        
        for (int i = 2; i < coordinates.size(); ++i) {
            if (A * coordinates[i][0] + B * coordinates[i][1] + C != 0) {
                return false;
            }
        }
        
        return true;
    }
};