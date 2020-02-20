static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= max_duplicates) {
            return nums.size();
        }
        
        int current_position = 0;
        int block_left = 0;
        int block_right = 0;
        
        while (block_right < nums.size()) {
            while (block_right < nums.size() && nums[block_left] == nums[block_right]) {
                ++block_right;
            }
            
            for (int i = 0; i < min(max_duplicates, block_right-block_left); ++i) {
                nums[current_position++] = nums[block_left];
            }
            
            block_left = block_right;
        }
        
        return current_position;
    }
    
    int max_duplicates = 2;
};