static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> result;

        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for (const auto& word: words) {
            string morse = "";
            for (const auto& symbol: word) {
                morse += codes[symbol-'a'];
            }
            result.insert(morse);
        }

        return result.size();
    }
};