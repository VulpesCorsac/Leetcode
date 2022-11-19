class Uber {
public:
    Uber() {
        
    }
    
    void addCab(int cabX, int cabY) {
        cabs.insert({cabX, cabY});
    }
    
    vector<int> startTrip(int customerID, int customerX, int customerY) {
        if (cabs.empty())
            return {-1, -1};

        const auto nearestCab = getNearestCabs(1, customerX, customerY)[0];
        const auto cabX = nearestCab[0];
        const auto cabY = nearestCab[1];
        cabs.erase(cabs.find({cabX, cabY}));
        assigned.emplace(customerID);
        return {cabX, cabY};
    }
    
    void endTrip(int customerID, int customerX, int customerY) {
        if (!assigned.count(customerID))
            return;

        assigned.erase(customerID);
        addCab(customerX, customerY);
    }
    
    vector<vector<int>> getNearestCabs(int k, int x, int y) {
        auto comp = [&x, &y, this] (const pair<int, int>& p1, const pair<int, int>& p2) {
            const auto dist1 = dist(x, y, p1.first, p1.second);
            const auto dist2 = dist(x, y, p2.first, p2.second);
            if (dist1 != dist2)
                return dist1 < dist2;
            return (p1.first != p2.first) ? p1.first < p2.first : p1.second < p2.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (const auto& cab: cabs) {
            if (pq.size() < k)
                pq.push(cab);
            else if (comp(cab, pq.top())) {
                pq.pop();
                pq.push(cab);
            }
        }
        
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        
        sort(ans.begin(), ans.end(), [] (const vector<int>& p1, const vector<int>& p2) {
            return (p1[0] != p2[0]) ? p1[0] < p2[0] : p1[1] < p2[1];
        });
        return ans;
    }

private:
    double dist(int x0, int y0, int x1, int y1) {
        return sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    }
    
    multiset<pair<int, int>> cabs;
    unordered_set<int> assigned;
};

/**
 * Your Uber object will be instantiated and called as such:
 * Uber* obj = new Uber();
 * obj->addCab(cabX,cabY);
 * vector<int> param_2 = obj->startTrip(customerID,customerX,customerY);
 * obj->endTrip(customerID,customerX,customerY);
 * vector<vector<int>> param_4 = obj->getNearestCabs(k,x,y);
 */
