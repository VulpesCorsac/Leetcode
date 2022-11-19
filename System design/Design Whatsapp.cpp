class WhatsApp {
public:
    WhatsApp() {
        
    }
    
    void sendMessage(int toUser, string message) {
        messagesForUser[toUser].push_back(message);
    }
    
    int createGroup(vector<int> initialUsers) {
        usersInGroup[nextGroupId] = unordered_set<int>(initialUsers.begin(), initialUsers.end());
        return nextGroupId++;
    }
    
    void addUserToGroup(int groupId, int userId) {
        if (usersInGroup.count(groupId))
            usersInGroup[groupId].insert(userId);
    }
    
    void sendGroupMessage(int fromUser, int groupId, string message) {
        if (!usersInGroup.count(groupId))
            return;
        if (!usersInGroup[groupId].count(fromUser)) 
            return;
        
        for (const auto& id: usersInGroup[groupId])
            if(id != fromUser)
                sendMessage(id, message);
    }
    
    vector<string> getMessagesForUser(int userId) {
        auto result = messagesForUser[userId];
        reverse(result.begin(), result.end());
        return result;
    }

private:
    unordered_map<int, vector<string>> messagesForUser;
    unordered_map<int, unordered_set<int>> usersInGroup;
    int nextGroupId = 1;
};

/**
 * Your WhatsApp object will be instantiated and called as such:
 * WhatsApp* obj = new WhatsApp();
 * obj->sendMessage(toUser,message);
 * int param_2 = obj->createGroup(initialUsers);
 * obj->addUserToGroup(groupId,userId);
 * obj->sendGroupMessage(fromUser,groupId,message);
 * vector<string> param_5 = obj->getMessagesForUser(userId);
 */
