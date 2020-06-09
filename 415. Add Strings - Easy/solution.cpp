static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }

        reverse(num1.begin(), num1.end());
        num1 += '0';
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < num1.size(); ++i) {
            if (i < num2.length()) {
                num1[i] = num1[i] + num2[i] - '0';
            }

            if (num1[i] > '9' && i < num1.size()-1) {
                int tmp = num1[i] - '0';

                num1[i+1] += tmp / 10;
                num1[i] = '0' + tmp % 10;
            }
        }

        while (num1.length() > 1 && num1[num1.length()-1] == '0') {
            num1.resize(num1.length()-1);
        }

        reverse(num1.begin(), num1.end());
        return num1;
    }
};