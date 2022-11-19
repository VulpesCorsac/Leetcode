class LogAggregator {
public:
    LogAggregator(int machines, int services) 
        : machines(machines)
        , services(services) {
        
    }
    
    void pushLog(int logId, int machineId, int serviceId, string message) {
        maplogsString[logId] = message;
        
        if (maplogsIdMachines.find(machineId) != maplogsIdMachines.end())
            maplogsIdMachines[machineId].push_back(logId);
        else
            maplogsIdMachines[machineId] = { logId };

        if (maplogsIdServices.find(serviceId) != maplogsIdServices.end())
            maplogsIdServices[serviceId].push_back(logId);
        else
            maplogsIdServices[serviceId] = { logId };
    }
    
    vector<int> getLogsFromMachine(int machineId) {
        return maplogsIdMachines[machineId];
    }
    
    vector<int> getLogsOfService(int serviceId) {
        return maplogsIdServices[serviceId];
    }
    
    vector<string> search(int serviceId, string searchString) {
        vector<string> filteredLogs;
        for (const auto& logId: maplogsIdServices[serviceId]) {
            string message = maplogsString[logId];
            if (message.find(searchString) != string::npos)
                filteredLogs.push_back(message);
        }
        return filteredLogs;
    }
    
private:
    int machines;
    int services;
    unordered_map<int,vector<int>> maplogsIdMachines;
    unordered_map<int,vector<int>> maplogsIdServices;
    unordered_map<int,string> maplogsString;
};

/**
 * Your LogAggregator object will be instantiated and called as such:
 * LogAggregator* obj = new LogAggregator(machines, services);
 * obj->pushLog(logId,machineId,serviceId,message);
 * vector<int> param_2 = obj->getLogsFromMachine(machineId);
 * vector<int> param_3 = obj->getLogsOfService(serviceId);
 * vector<string> param_4 = obj->search(serviceId,searchString);
 */
