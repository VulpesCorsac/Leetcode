class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> unique;
        for (const auto& item: A) {
            if (unique.count(item)) {
                return item;
            } else {
                unique.insert(item);
            }
        }
        
        return 0;
    }
};