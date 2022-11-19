class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        auto& tweets = data[userId];
        tweets.push_back({time++, tweetId});
        while (tweets.size() > MAX)
            tweets.pop_front();
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap; 
        for (const auto& it: data[userId])
            maxHeap.push(it);
        for (const auto& friendId: friends[userId])
            for (const auto& it: data[friendId])
                maxHeap.push(it);
        
        vector<int> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            if (res.size() == MAX) 
                break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }

private:
    unordered_map<int,unordered_set<int>> friends;
    unordered_map<int,deque<pair<int,int>>> data;
    uint64_t time = 0;
    const int MAX = 10;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
