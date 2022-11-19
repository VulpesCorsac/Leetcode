class RateLimiter {
public:
    RateLimiter(int n, int t) 
        : capacity(n)
        , timeframe(t) { 
    }
    
    bool shouldAllow(int timestamp) {
        while (!d.empty() && d.front() <= timestamp-timeframe)
            d.pop_front();
        
        if (d.size() >= capacity)
            return false;
        
        d.push_back(timestamp);
        return true;
    }
    
private:
    deque<int> d;
    int capacity;
    int timeframe;
};

/**
 * Your RateLimiter object will be instantiated and called as such:
 * RateLimiter* obj = new RateLimiter(n, t);
 * bool param_1 = obj->shouldAllow(timestamp);
 */
