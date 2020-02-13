class Solution {
public:
    string defangIPaddr(string address) {
        string result = "";
        
        for (const auto& symbol: address) {
            if (symbol == '.') {
                result += "[.]";
            } else {
                result += symbol;
            }
        }
        
        return result;
    }
};