static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k < 1 || t < 0) {
            return false;
        }

        unordered_map < long long, long long > bucket;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                bucket.erase((static_cast < long long > (nums[i-k-1]) - INT_MIN) / static_cast < long long > (t + 1));
            }

            long long num = static_cast < long long > (nums[i]) - INT_MIN;
            long long id = num / (static_cast < long long >(t) + 1);

            if ( bucket.count(id  ) ||
                (bucket.count(id-1) && nums[i] - bucket[id-1] <= t) ||
                (bucket.count(id+1) && bucket[id+1] - nums[i] <= t)) {

                return true;
            }

            bucket[id] = nums[i];
        }

        return false;
    }
};