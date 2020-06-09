static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            swap(a, b);
        }

        int ptra = a.length() - 1;
        int ptrb = b.length() - 1;

        int carry = 0;

        string result;

        while(ptra >= 0 && ptrb >= 0) {
            int n = a[ptra--] - '0' + b[ptrb--] - '0' + carry;
            result.push_back((n % 2) + '0');
            carry = n / 2;
        }

        while(ptra >= 0) {
            int n = a[ptra--] - '0' + carry;
            result.push_back((n % 2) + '0');
            carry = n / 2;
        }

        if (carry) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};