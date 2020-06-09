static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool canVisitAllRooms(vector < vector < int > >& rooms) {
        int visited_cnt = 1;
        vector < bool > visited(rooms.size(), false);
        visited[0] = true;

        queue < int > to_visit({0});
        while (!to_visit.empty()) {
            int room = to_visit.front();
            to_visit.pop();

            for (const auto& neighbor : rooms[room]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    to_visit.push(neighbor);
                    ++visited_cnt;
                }
            }
        }
        return visited_cnt == rooms.size();
    }
};