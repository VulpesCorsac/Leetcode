static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int openLock(vector < string >& deadends, string target) {
        unordered_set < string > dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            return -1;
        }
        if (target == "0000") {
            return 0;
        }
        
        queue < string > q;
        q.push("0000");
        for (int move = 1; !q.empty(); ++move) {
            for (int n = q.size(); n > 0; --n) {
                string current = q.front();
                q.pop();
                
                for (int position = 0; position < 4; ++position) {
                    for (int diff = 1; diff <= 9; diff += 8) {
                        string s = current;
                        s[position] = (s[position] - '0' + diff) % 10 + '0';
                        
                        if (s == target) {
                            return move;
                        }
                        
                        if (!dead.count(s)) {
                            q.push(s);
                            dead.insert(s);
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};