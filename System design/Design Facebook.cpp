class Facebook {
public:
    Facebook() {
        
    }
    
    void writePost(int userId, string postContent) {
        posts[userId][time++] = postContent;
    }
    
    void addFriend(int user1, int user2) {
        friends[user1].insert(user2);
        friends[user2].insert(user1);
    }
    
    vector<string> showPosts(int userId) {
        vector<pair<int,string>> postTime;
        for (const auto& friendId: friends[userId])
            for (const auto& post: posts[friendId])
                postTime.push_back(post);
        sort(postTime.begin(), postTime.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
            
        vector<string> res;
        for(auto& [time, post]: postTime)
            res.push_back(std::move(post));
        return res;
    }

private:
    int time = 0;
    unordered_map<int,unordered_set<int>> friends;
    unordered_map<int,unordered_map<int, string>> posts;
};

/**
 * Your Facebook object will be instantiated and called as such:
 * Facebook* obj = new Facebook();
 * obj->writePost(userId,postContent);
 * obj->addFriend(user1,user2);
 * vector<string> param_3 = obj->showPosts(userId);
 */
