class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result;
        
        int counter = 0;
        for (auto it = S.rbegin(); it != S.rend(); ++it) {
            if (*it != '-') {
                if (counter > 0 && counter % K == 0) {
                    result += '-';
                }
                ++counter;
                result += toupper(*it);
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};