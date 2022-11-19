#define ALL(c) c.begin(), c.end()

class MonitoringSystem {
public:    
    MonitoringSystem() {
        
    }
    
    void logLatency(string applicationName, string api, int latencyInMills) {
        latency[applicationName][api].push_back(latencyInMills);
    }
    
    void logError(string applicationName, string api, int errorCode) {
        ++error[applicationName][api][errorCode];
    }
    
    int getPercentileLatency(int percentile, string applicationName, string api) {
        auto temp = latency[applicationName][api];
        if (temp.empty())
            for (const auto& [_, item]: latency[applicationName])
                temp.insert(temp.end(), ALL(item));
            
        sort(ALL(temp));
        int index = temp.size() * percentile / 100 - 1;
        if (index < 0)
            index = 0;
        
        return temp[index];
    }
    
    vector<int> getTopErrors(string applicationName, string api) {
        vector<pair<int, int>> temp;
        if (error[applicationName][api].size() < 3)
            for (const auto& [_, item]: error[applicationName])
                temp.insert(temp.end(), ALL(item));
        else
            temp.insert(temp.end(), ALL(error[applicationName][api]));
        
        sort(ALL(temp), [](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        });
        
        vector<int> res;
        for (int i = 0; i < min<int>(Max, temp.size()); ++i)
            res.push_back(temp[i].first);
        return res;
    }

private:
    static constexpr const int Max = 3;
    unordered_map<string, unordered_map<string, unordered_map<int, int>>> error;
    unordered_map<string, unordered_map<string, vector<int>>> latency;
};

/**
 * Your MonitoringSystem object will be instantiated and called as such:
 * MonitoringSystem* obj = new MonitoringSystem();
 * obj->logLatency(applicationName,api,latencyInMills);
 * obj->logError(applicationName,api,errorCode);
 * int param_3 = obj->getPercentileLatency(percentile,applicationName,api);
 * vector<int> param_4 = obj->getTopErrors(applicationName,api);
 */
