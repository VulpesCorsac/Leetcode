static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class ZeroEvenOdd {
private:
    int n;
    atomic < int > counter = 0;

public:
    ZeroEvenOdd(int n) 
        : n(n) {
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function < void(int) > printNumber) {
        for (int i = 0; i < n; ++i) {
            while ((counter % 4 != 0) && (counter % 4 != 2)) { 
                this_thread::yield();
            }
            
            printNumber(0);
            ++counter;
        }
    }

    void odd(function < void(int) > printNumber) {
        for (int i = 1; i <= n; i += 2) {
            while (counter % 4 != 1) {
                this_thread::yield();
            }
            
            printNumber(i);
            ++counter;
        }
    }

    void even(function < void(int) > printNumber) {
        for (int i = 2; i <= n; i += 2) {
            while (counter % 4 != 3) { 
                this_thread::yield();
            }
            
            printNumber(i);
            ++counter;
        }
    }
};