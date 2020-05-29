static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < vector < int > > graph;
    vector < int > visited;
    
    bool dfs(int v) {
        if (visited[v] == 1) {
            return false;
        }
        if (visited[v] == 2) {
            return true;
        }
        
        visited[v] = 1;
        for (const auto& next : graph[v]) {
            if (!dfs(next)) {
                return false;
            }
        }
        visited[v] = 2;
        
        return true;
    }
    
    bool canFinish(int numCourses, vector < vector < int > >& prerequisites) {
        graph.resize(numCourses);
        visited.assign(numCourses, 0);
        
        for (const auto& item : prerequisites) {
            auto before = item[0];
            auto after  = item[1];
            
            graph[before].push_back(after);            
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) {
                return false;
            }
        }
        
        return true;
    }
};