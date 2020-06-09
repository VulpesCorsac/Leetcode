static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set < char > jewels(J.begin(), J.end());

        int result = 0;

        for (const auto& stone: S) {
            if (jewels.count(stone)) {
                ++result;
            }
        }

        return result;
    }
};