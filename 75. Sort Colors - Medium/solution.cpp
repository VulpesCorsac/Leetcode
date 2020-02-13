static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    void sortColors2Pass(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        for (const auto& item: nums) {
            if (item == 0) {
                ++zeros;
            } else if (item == 1) {
                ++ones;
            } else {
                ++twos;
            }   
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i < zeros) {
                nums[i] = 0;
            } else if (i < zeros + ones) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
		
		return;
    }

    void sortColors1Pass(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                ++mid;
                ++low;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                --high;
            } else {
                ++mid;
            }
        }
    }

    void sortColors(vector<int>& nums) {
        return sortColors1Pass(nums);
    }
};