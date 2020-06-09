static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        auto ans = std::move(image);

        cout << "Ok" << endl;

        int dr[] = {+1, -1,  0,  0};
        int dc[] = { 0,  0, +1, -1};
        int Q = ans[sr][sc];
        int R = ans.size();
        int C = ans[0].size();

        queue < pair < int, int > > fill;
        fill.push({sr, sc});
        while (!fill.empty()) {
            auto cell = fill.front();
            fill.pop();
            if (ans[cell.first][cell.second] != newColor) {
                ans[cell.first][cell.second]  = newColor;

                for (int i = 0; i < 4; ++i) {
                    auto r = cell.first  + dr[i];
                    auto c = cell.second + dc[i];

                    if (0 <= r && r < R && 0 <= c && c < C && ans[r][c] == Q) {
                        fill.push({r, c});
                    }
                }
            }
        }

        return ans;
    }
};