static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    bool isPalindrome(int x) {
        string s1 = to_string(x);
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return s1 == s2;
    }
};