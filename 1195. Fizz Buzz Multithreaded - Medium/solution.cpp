static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class FizzBuzz {
private:
    int n;
    int cnt;
    mutex m;
    condition_variable cv;

public:
    FizzBuzz(int n)
        : n(n)
        , cnt(1) {
    }

    // printFizz() outputs "fizz".
    void fizz(function < void() > printFizz) {
        while (true) {
            unique_lock lock(m);
            while (cnt <= n && (cnt % 3 != 0 || cnt % 5 == 0)) {
                cv.wait(lock);
            }
            if (cnt > n) {
                return;
            }

            printFizz();
            ++cnt;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function < void() > printBuzz) {
        while (true) {
            unique_lock lock(m);
            while (cnt <= n && (cnt % 3 == 0 || cnt % 5 != 0)) {
                cv.wait(lock);
            }
            if (cnt > n) {
                return;
            }

            printBuzz();
            ++cnt;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function < void() > printFizzBuzz) {
        while (true) {
            unique_lock lock(m);
            while (cnt <= n && (cnt % 3 != 0 || cnt % 5 != 0)) {
                cv.wait(lock);
            }
            if (cnt > n) {
                return;
            }

            printFizzBuzz();
            ++cnt;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function < void(int) > printNumber) {
        while (true) {
            unique_lock lock(m);
            while (cnt <= n && (cnt % 3 == 0 || cnt % 5 == 0)) {
                cv.wait(lock);
            }
            if (cnt > n) {
                return;
            }

            printNumber(cnt);
            ++cnt;
            cv.notify_all();
        }
    }
};