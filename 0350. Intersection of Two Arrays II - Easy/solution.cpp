static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map < int , int > nums1_map;
        unordered_map < int , int > nums2_map;

        for (const auto& item: nums1) {
            ++nums1_map[item];
        }
        for (const auto& item: nums2) {
            ++nums2_map[item];
        }

        vector < int > result;
        result.reserve(nums1.size() + nums2.size());

        for (const auto& item: nums1_map) {
            for (int i = 0; i < min(nums2_map[item.first], item.second); ++i) {
                result.push_back(item.first);
            }
        }

        return result;
    }
};