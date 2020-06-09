static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set < int > top3;
        for (const auto& num : nums) {
            top3.insert(num);
            if (top3.size() > 3) {
                top3.erase(top3.begin());
            }
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};