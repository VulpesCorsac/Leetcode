static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector < int > ford_bellman(n, 1e8);
        ford_bellman[src] = 0;
        
        for(int i = 0; i <= K; i++){
            vector < int > updated(ford_bellman);
            for(const auto& edje: flights) {
                updated[edje[1]] = min(updated[edje[1]], ford_bellman[edje[0]] + edje[2]);
            }
            ford_bellman = move(updated);
        }
        return ford_bellman[dst] == 1e8 ? -1 : ford_bellman[dst];
    }
};