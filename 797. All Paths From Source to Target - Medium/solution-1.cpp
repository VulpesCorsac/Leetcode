static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size();
        
        return subroutine(graph, 0);
    }
    
    vector<vector<int>> subroutine(vector<vector<int>>& graph, int current_point) {
        if (current_point == N-1) {
            return {{N-1}};
        } else {
            vector<vector<int>> result;
            
            for (const auto& next: graph[current_point]) {
                auto temp_result = subroutine(graph, next);
                for (const auto& path: temp_result) {
                    result.push_back({current_point});
                    result.back().insert(result.back().end(), path.begin(), path.end());
                }
            }
            
            return result;
        }
    }
    
    int N;
};