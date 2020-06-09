static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int numTilePossibilities(string tiles) {
        set < string > unique;

        sort(tiles.begin(), tiles.end());

        do {
            for (int st = 0; st < tiles.length(); ++st) {
                for (int len = 1; len <= tiles.length()-st; ++len) {
                    unique.insert(tiles.substr(st, len));
                }
            }
        } while (next_permutation(tiles.begin(), tiles.end()));

        return unique.size();
    }
};