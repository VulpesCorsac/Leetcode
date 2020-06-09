static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool judgeCircle(string moves) {
        int UD = 0;
        int LR = 0;

        for (const auto& symbol: moves) {
            switch(symbol) {
                case 'U': {++UD; break;}
                case 'D': {--UD; break;}
                case 'L': {++LR; break;}
                case 'R': {--LR; break;}
            }
        }

        return !UD && !LR;
    }
};