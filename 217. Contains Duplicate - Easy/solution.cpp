static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set < int > s(nums.begin(), nums.end());
        return nums.size() != s.size();
    }
};