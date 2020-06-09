static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int trusts [N+1];
        int trusted[N+1];
        for (int i = 0; i <= N; ++i) {
            trusts[i] = trusted[i] = 0;
        }

        for (int i = 0; i < trust.size(); ++i) {
            ++trusts [trust[i][0]];
            ++trusted[trust[i][1]];
        }

        for (int i = 1; i <= N; ++i) {
            if (trusts[i] == 0 && trusted[i] == N-1) {
                return i;
            }
        }

        return -1;
    }
};