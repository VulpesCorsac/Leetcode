static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    void recordPaths(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& results) {
        if (node == graph.size()-1) {
            results.push_back(path);
            return;
        }
        for (const int& other : graph[node]) {
            path.push_back(other);
            recordPaths(graph, other, path, results);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> results;
        vector<int> path(1, 0);
        recordPaths(graph, 0, path, results);
        return results;
    }
};