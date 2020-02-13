static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int first = 0; first < numbers.size()-1; ++first) {
            int second = lower_bound(numbers.begin()+first+1, numbers.end(), target-numbers[first]) - numbers.begin();
            if (second < numbers.size() && numbers[second] == target-numbers[first]) {
                return {first+1, second+1};
            }
        }
        return {};
    }
};