static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(
            stable_partition(nums.begin(),
                             nums.end(),
                             [&val](int n){return n!=val;}),
            nums.end());

        return nums.size();
    }
};