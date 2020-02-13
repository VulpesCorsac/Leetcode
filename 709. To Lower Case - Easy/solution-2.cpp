static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    string toLowerCase(string str) {        
        for (auto& symbol: str) {
            if (symbol >= 'A' && symbol <= 'Z') {
                symbol -= 'A' - 'a';
            }
        }
        
        return str;
    }
};