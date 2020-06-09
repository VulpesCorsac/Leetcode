static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

//            cout << nums[l] << " " << nums[m] << " " << nums[r] << "\n";

            if (nums[l] == target) {
                return l;
            }
            if (nums[m] == target) {
                return m;
            }
            if (nums[r] == target) {
                return r;
            }

            if (nums[m] > nums[l]) {
                if (target > nums[m]) {
                    l = m+1;
                } else {
                    if (target < nums[l]) {
                        l = m+1;
                    } else {
                        r = m-1;
                    }
                }
            } else {
                if (target < nums[m]) {
                    r = m-1;
                } else {
                    if (target > nums[r]) {
                        r = m-1;
                    } else {
                        l = m+1;
                    }
                }
            }
        }
        if (r+1 < nums.size() && nums[r+1] == target) {
            return r+1;
        }

        return -1;
    }
};