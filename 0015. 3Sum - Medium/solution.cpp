static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector < vector < int > > result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            } else {
                int twoSum = -nums[i];

                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    int sum = nums[left] + nums[right];

                    if (sum < twoSum) {
                        ++left;
                    } else if (sum > twoSum) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[left], nums[right]});
                        ++left;
                        --right;

                        while (left < right && nums[left-1] == nums[left]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right+1]) {
                            --right;
                        }
                    }
                }
            }
        }

        return result;
    }
};