static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        long long ans1 = INT_MIN, ans2 = INT_MAX, ans3 = INT_MAX;
        long long sum = 0;
        for (const auto& item : A)
            sum += item;
        
        auto curr = ans1;
        for (auto it = A.begin(); it != A.end(); ++it) {
            curr = *it + max(curr, 0LL);
            ans1 = max(curr, ans1);
        }
        
        curr = ans1;
        for (auto it = A.begin()+1; it != A.end(); ++it) {
            curr = *it + min(curr, 0LL);
            ans2 = min(curr, ans2);
        }
        ans2 = sum - ans2;

        curr = ans3;
        for (auto it = A.begin(); it != A.end()-1; ++it) {
            curr = *it + min(curr, 0LL);
            ans3 = min(curr, ans3);
        }
        ans3 = sum - ans3;
        
        return max(ans1, max(ans2, ans3));
    }
};