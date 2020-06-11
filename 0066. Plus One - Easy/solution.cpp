static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < int > plusOne(vector < int >& digits) {
        int i = digits.size()-1;
        ++digits[i];
        while (digits[i] >= 10) {
            digits[i] -= 10;
            if (i == 0) {
                digits.insert(digits.begin(),1);
            } else {
                digits[--i] += 1;
            }
        }

        return digits;
    }
};