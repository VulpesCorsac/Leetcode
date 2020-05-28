static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector < int > graph[N+1];
        
        for(auto dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        vector < int > color(N + 1, 0);
        
        function < bool(int, int) > dfs = [&](int v, int c) {
            if(color[v] != 0) {
                return color[v] == c;
            }

            color[v] = c;
            for(auto next : graph[v]) {
                if(!dfs(next, -c)) {
                    return false;
                }
            }
            return true;
        };

        for(int i = 1; i <= N; i++) {
            if(color[i] == 0 && !dfs(i, 1)) {
                return false;
            }
        }
        
        return true;        
    }
};