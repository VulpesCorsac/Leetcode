static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto zeros = count(arr.begin(), arr.end(), 0);
        auto n = arr.size();

        for (int i = n-1; i >= 0; --i) {
            if (i + zeros < n) {
                arr[i+zeros] = arr[i];
            }

            if (!arr[i]) {
                --zeros;
                if (i + zeros < n) {
                    arr[i+zeros] = 0;
                }
            }
        }
    }
};