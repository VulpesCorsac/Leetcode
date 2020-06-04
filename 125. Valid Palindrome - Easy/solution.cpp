static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                ++l;
            }
            while (l < r && !isalnum(s[r])) {
                --r;
            }
                        
            if (tolower(s[l++]) != tolower(s[r--])) {
                return false;
            }
        }
        
        return true;
    }
};