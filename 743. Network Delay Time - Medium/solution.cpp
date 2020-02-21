static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector < int > lighted(N+1, false);
        int lighted_amount = 0;
        int current_time = 0;
        int current_u = K;
        priority_queue < pair < int , int > > to_light;
        
        to_light.push({-current_time , current_u});
        while (!to_light.empty()) {
            current_u    = to_light.top().second;
            current_time = to_light.top().first;
            
//            cout << "Current: " << current_time << " " << current_u << "\n";
            to_light.pop();
            
            if (lighted[current_u]) {
                continue;
            }
            
            lighted[current_u] = true;
            ++lighted_amount;
            
            if (lighted_amount == N) {
                break;
            }
            
            for (const auto& edge : times) {
                if (edge[0] == current_u) {
                    if (!lighted[edge[1]]) {
//                        cout << "To light: " << current_time - edge[2] << " " << edge[1] << "\n";
                        to_light.push({current_time - edge[2], edge[1]});
                    }
                }
            }
        }
        
        
        return (lighted_amount == N ? -current_time : -1);
    }
};