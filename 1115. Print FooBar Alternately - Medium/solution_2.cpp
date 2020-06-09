static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class FooBar {
private:
    int n;
    std::atomic < bool > b {true};

public:
    FooBar(int n)
        : n(n) {
    }

    void foo(std::function < void() > printFoo) {
        for (int i = 0; i < n; i++) {
            while (!b.load(std::memory_order_acquire)) {
                std::this_thread::yield();
            };

            printFoo();

            b.store(false, std::memory_order_release);
        }
    }

    void bar(std::function < void() > printBar) {
        for (int i = 0; i < n; i++) {
            while (b.load(std::memory_order_acquire)) {
                std::this_thread::yield();
            };

            printBar();
            b.store(true, std::memory_order_release);
        }
    }
};