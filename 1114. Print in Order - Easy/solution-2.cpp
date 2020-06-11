static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Foo {
private:
    std::mutex mu;
    std::condition_variable cv;
    int c = 1;

public:
    void first(function < void() > printFirst) {
        std::unique_lock < std::mutex > locker(mu);
        cv.wait(locker, [this] { return this->c == 1; } );

        printFirst();

        c = 2;
        cv.notify_all();
    }

    void second(function < void() > printSecond) {
        std::unique_lock < std::mutex > locker(mu);
        cv.wait(locker, [this] { return this->c == 2; } );

        printSecond();

        c = 3;
        cv.notify_all();
    }

    void third(function < void() > printThird) {
        std::unique_lock < std::mutex > locker(mu);
        cv.wait(locker, [this] { return this->c == 3; } );

        printThird();

        c = 4;
        cv.notify_all();
    }
};