static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if (tree.size() < 3) {
            return tree.size();
        }

        int ans = 1;
        int l = 0;
        int r = 0;

        map < int , int > types;

        while (r < tree.size()) {
            if (types.count(tree[r]) > 0 || types.size() < 2) {
                ++types[tree[r]];

                ++r;

                ans = max(ans, r-l);
            } else {
                --types[tree[l]];

                if (types[tree[l]] == 0) {
                    types.erase(tree[l]);
                }

                ++l;
            }
        }

        return ans;
    }
};