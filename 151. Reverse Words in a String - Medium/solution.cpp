static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return s;
        }
        
        std::istringstream iss(s);
        string result = "";

        string w;
        while (iss >> w) {
            result = w + " " + result;
        }
        
        if (result.size() > 0) {
            result.pop_back();
        }

        return result;
    }
};