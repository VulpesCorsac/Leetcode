#define ALL(c) c.begin(), c.end()

class DCLoadBalancer {
public:
    DCLoadBalancer() {

    }

    void addMachine(int machineId, int capacity) {
        resources.push({capacity, machineId});
    }

    void removeMachine(int machineId) {
        PriorityQueue temp;
        while (!resources.empty()) {
            const auto top = resources.top();
            resources.pop();
            if (top.id != machineId)
                temp.push(top);
        }
        resources = std::move(temp);

        for (const auto& appId: appsOnMachine[machineId])       
            if (addApplication(appId, loadOfApp[appId]) == -1)
                appToMachine.erase(appId),
                loadOfApp.erase(appId);

        appsOnMachine.erase(machineId);
    }

    int addApplication(int appId, int loadUse) {
        if (!resources.empty()) {
            auto top = resources.top();
            if (top.capacity < loadUse)
                return -1;    
            
            resources.pop();
            top.capacity -= loadUse;
            appToMachine[appId] = top.id;
            appsOnMachine[top.id].push_back(appId);
            loadOfApp[appId] = loadUse;
            resources.push(top);
            return top.id;
        }
        
        return -1;
    }

    void stopApplication(int appId) {
        const int machineId = appToMachine[appId];

        PriorityQueue temp;
        while (!resources.empty()) {
            auto top = resources.top();
            resources.pop();
            if (top.id == machineId)
                top.capacity += loadOfApp[appId];
            temp.push(top);
        }
        resources = std::move(temp);

        if (auto it = find(ALL(appsOnMachine[machineId]), appId);
            it != appsOnMachine[machineId].end())
            appsOnMachine[machineId].erase(it);
        appToMachine.erase(appId);
        loadOfApp.erase(appId);
    }

    vector<int> getApplications(int machineId) {
        if (appsOnMachine[machineId].size() < MaxSize)
            return appsOnMachine[machineId];
        auto it = appsOnMachine[machineId].begin();
        return vector<int>(it, it+MaxSize);
    }

private:
    struct Resources {
        int capacity;
        int id;
    };
    
    class Comparator {
    public:
        bool operator() (const Resources& a, const Resources& b) {
            if(a.capacity == b.capacity)
                return a.id > b.id;
            return a.capacity < b.capacity;
        }
    };
    
    static constexpr const int MaxSize = 10;
    
    using PriorityQueue = priority_queue<Resources, vector<Resources>, Comparator>;
    PriorityQueue resources;
    unordered_map<int, int> appToMachine;
    unordered_map<int, int> loadOfApp;
    unordered_map<int, vector<int>> appsOnMachine;
};

/**
 * Your DCLoadBalancer object will be instantiated and called as such:
 * DCLoadBalancer* obj = new DCLoadBalancer();
 * obj->addMachine(machineId,capacity);
 * obj->removeMachine(machineId);
 * int param_3 = obj->addApplication(appId,loadUse);
 * obj->stopApplication(appId);
 * vector<int> param_5 = obj->getApplications(machineId);
 */
