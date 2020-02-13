static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) {
            return false;
        }
        if (!matrix[0].size()) {
            return false;
        }
        
        int low = 0;
        int high = matrix.size()-1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            if (matrix[mid][0] < target) {
                low = mid+1;
            } else if (matrix[mid][0] == target) {
                return true;
            } else {
                high = mid-1;
            }
        }
        
        if (matrix[low][0] > target && low > 0) {
            --low;
        }
        
        return binary_search(matrix[low].begin(), matrix[low].end(), target);
    }
};