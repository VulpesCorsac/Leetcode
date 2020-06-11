static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class ZeroEvenOdd {
private:
    int n;
    int cnt;
    bool print_zero;
    mutex m;
    condition_variable cv;
public:
    ZeroEvenOdd(int n)
        : n(n)
        , cnt(1)
        , print_zero(true) {
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function < void(int) > printNumber) {
        while (cnt <= n) {
            unique_lock < mutex > lock(m);
            cv.wait(lock, [this] () { return print_zero; } );

            if (cnt <= n) {
                printNumber(0);
            }
            print_zero = false;
            cv.notify_all();
        }
        return;
    }

    void odd(function < void(int) > printNumber) {
        while (cnt <= n) {
            unique_lock < mutex > lock(m);
            cv.wait(lock, [this] () { return !print_zero && cnt & 1; } );

            if (cnt <= n) {
                printNumber(cnt++);
                print_zero = true;
            }

            cv.notify_all();
        }
        return;
    }

    void even(function < void(int) > printNumber) {
        while (cnt <= n) {
            unique_lock < mutex > lock(m);
            cv.wait(lock, [this] () { return !print_zero && !(cnt & 1); } );

            if (cnt <= n) {
                printNumber(cnt++);
                print_zero = true;
            }

            cv.notify_all();
        }
        return;
    }
};