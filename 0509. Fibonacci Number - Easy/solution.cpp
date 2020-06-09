static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int fib1(int N) {
        if (N <= 1) {
            return N;
        }

        return fib1(N-1) + fib1(N-2);
    }

    int fib2(int N) {
        double golden_plus  = (1 + sqrt(5)) / 2;
        double golden_minus = (1 - sqrt(5)) / 2;
        return static_cast < int > ((pow(golden_plus, N) - pow(golden_minus, N)) / sqrt(5));
    }

    int fib3(int N) {
        if (N <= 1) {
            return N;
        }

        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 2; i <= N; ++i) {
            c = a+b;
            a = b;
            b = c;

        }

        return c;
    }

    int fib(int N) {
        return fib3(N);
    }
};