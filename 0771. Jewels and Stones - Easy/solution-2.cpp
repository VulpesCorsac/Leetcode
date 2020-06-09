static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int solution = 0;

        for(int i = 0; i < S.size(); ++i){
            if(J.find(S[i]) != string::npos){
                solution++;
            }
        }

        return solution;
    }
};