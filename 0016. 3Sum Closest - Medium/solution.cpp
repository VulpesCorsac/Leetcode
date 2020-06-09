static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int threeSumClosest1(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                for (int k = j+1; k < nums.size(); ++k) {
                    int temp = nums[i] + nums[j] + nums[k];
                    if (abs(target - temp) < abs(target - closest)) {
                        closest = temp;
                    }
                }
            }
        }

        return closest;
    }

    int threeSumClosest2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size()-2; ++i) {
            int left = i+1;
            int right = nums.size()-1;

            while (left < right) {
                int temp = nums[i] + nums[left] + nums[right];
                if (abs(target - temp) < abs(target - closest)) {
                    closest = temp;
                }

                if (temp < target) {
                    ++left;
                } else if (temp > target) {
                    --right;
                } else {
                    return target;
                }
            }
        }

        return closest;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        return threeSumClosest2(nums, target);
    }
};