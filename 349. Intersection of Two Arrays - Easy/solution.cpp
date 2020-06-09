static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        set < int > nums1_set(nums1.begin(), nums1.end());
        set < int > nums2_set(nums2.begin(), nums2.end());

        vector < int > result(nums1.size() + nums2.size());

        result.resize(set_intersection(nums1_set.begin(), nums1_set.end(),
                                       nums2_set.begin(), nums2_set.end(),
                                       result.begin()                     )-result.begin());

        return result;
    }

    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        unordered_set < int > nums1_set(nums1.begin(), nums1.end());
        unordered_set < int > nums2_set(nums2.begin(), nums2.end());

        vector < int > result;
        result.reserve(nums1.size() + nums2.size());

        for (const auto& item: nums1_set) {
            if (nums2_set.count(item)) {
                result.push_back(item);
            }
        }

        return result;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        return intersection2(nums1, nums2);
    }

};