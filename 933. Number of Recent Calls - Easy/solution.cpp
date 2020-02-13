static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class RecentCounter {
public:
    RecentCounter() {
        while (!q.empty()) {
            q.pop();
        }
    }
    
    int ping(int t) {
        q.push(t);
        
        while (!q.empty() && t - q.front() > 3000) {
            q.pop();
        }
        
        return q.size();
    }
    
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */