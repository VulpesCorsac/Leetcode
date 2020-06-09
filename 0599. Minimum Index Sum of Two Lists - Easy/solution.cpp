static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map < string , int > m;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
        }

        vector < string > ans;
        int min_sum = INT_MAX;
        for (int j = 0; j < list2.size(); ++j) {
            auto found = m.find(list2[j]);

            if (found != m.end()) {
                int sum = j + (*found).second;
                if (sum < min_sum) {
                    min_sum = sum;
                    ans.clear();
                    ans.push_back(std::move(list2[j]));
                } else if (sum == min_sum) {
                    ans.push_back(std::move(list2[j]));
                }
            }
        }

        return ans;
    }
};