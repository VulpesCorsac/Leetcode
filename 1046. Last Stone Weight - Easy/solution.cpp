static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 0) {
            return 0;
        }
        if (stones.size() == 1) {
            return stones[0];
        }

        sort(stones.begin(), stones.end());

        int idx = stones.size()-1;

        if (stones[idx-1] == stones[idx]) {
            stones.resize(idx-1);

            return lastStoneWeight(stones);
        } else {
            stones[idx-1] = stones[idx] - stones[idx-1];

            stones.resize(idx);

            return lastStoneWeight(stones);
        }
    }
};