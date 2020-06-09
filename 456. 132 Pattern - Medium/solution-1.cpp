static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }

        multiset<int> left = {nums[0]};
        multiset<int> right(nums.begin()+2, nums.end());

        for (size_t i = 1; i < nums.size()-1; ++i) {
            auto it_right = right.lower_bound(nums[i]);
            if (it_right != right.begin()) {
                --it_right;

                auto it_left = left.lower_bound(*it_right);
                if (it_left != left.begin()) {
                    return true;
                }
            }

            left.insert(nums[i]);
            right.erase(right.find(nums[i+1]));
        }

        return false;
    }
};