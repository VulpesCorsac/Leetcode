static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int left = 0, len = citations.size(), right = len-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= (len-mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return len - left;
    }
};