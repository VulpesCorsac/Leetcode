static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector < int > left  = minLen(arr, target);
        vector < int > arrReverse(arr.rbegin(), arr.rend());
        vector < int > right = minLen(arrReverse, target);

        const int n = arr.size();
        int min_val = n + 1;
        for(int i = 0; i < n-1; ++i) {
            min_val = min(min_val, left[i] + right[n-1-i-1]);
        }

        return min_val == n + 1 ? -1 : min_val;
    }

    vector < int > minLen(const vector < int > &arr, int target) {
        const int n = arr.size();
        vector < int > presum(n, 0);
        vector < int > ans(n, n + 1);
        unordered_map < int, int > idx;
        idx[0] = -1;
        for(int i = 0; i < n; ++i) {
            presum[i] = i == 0 ? arr[i] : arr[i] + presum[i-1];
            int len = n + 1;
            if(idx.count(presum[i] - target)) {
                len = i - idx[presum[i]-target];
            }
            idx[presum[i]] = i;
            ans[i] = i == 0 ? len : min(ans[i-1], len);
        }
        return ans;
    }

};