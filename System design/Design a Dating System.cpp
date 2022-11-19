class Tinder {
public:    
    Tinder() {
        
    }
    
    void signup(int userId, int gender, int preferredGender, int age, int minPreferredAge, int maxPreferredAge, vector<string> interests) {
        userById[userId] = User(userId, gender, preferredGender, age, minPreferredAge, maxPreferredAge, interests);
        userIdsByGenderAge[gender].emplace(age, userId);
    }
    
    vector<int> getMatches(int userId) {
        if (!userById.count(userId)) 
            return {};
        
        const auto& user = userById[userId];
        const auto& minPrefAge = user.minPreferredAge;
        const auto& maxPrefAge = user.maxPreferredAge;
        const auto& data = userIdsByGenderAge[user.preferredGender];
        
        auto lower       = data.lower_bound(minPrefAge);
        const auto upper = data.upper_bound(maxPrefAge);
        if (lower == data.end() || upper == data.begin() || lower->first > maxPrefAge)
            return {};

        auto comp = [] (const pair<int, int>& p1, const pair<int, int>& p2) {
            return (p1.first != p2.first) ? p1.first < p2.first : p1.second > p2.second;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        while (lower != upper) {
            if (const auto& [_, id] = *lower; id != userId)
                if (auto common = commonInterests(userId, id))
                    pq.push({common, id});
            ++lower;
        }
        
        vector<int> ans;
        for (int i = 0; i < MAX && !pq.empty(); ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
private:
    struct User {
        User() = default;
        
        User(int userId, int gender, int preferredGender, int age, int minPreferredAge, int maxPreferredAge, vector<string> interests) 
            : userId(userId) 
            , gender(gender)
            , preferredGender(preferredGender)
            , age(age)
            , minPreferredAge(minPreferredAge)
            , maxPreferredAge(maxPreferredAge)
            , interests(interests.begin(), interests.end()) {
        }
        
        int userId;
        int gender;
        int preferredGender;
        int age;
        int minPreferredAge;
        int maxPreferredAge;
        unordered_set<string> interests;
    };

    int commonInterests(int x, int y) {
        return commonInterests(userById[x].interests, userById[y].interests);
    }
    
    int commonInterests(const unordered_set<string>& x, const unordered_set<string>& y) {
        int ans = 0;
        for (auto& str : x)
            if (y.count(str))
                ++ans;
        return ans;
    }
    
    multimap<int, int> userIdsByGenderAge[2];
    unordered_map<int, User> userById;
    const int MAX = 5;
};
