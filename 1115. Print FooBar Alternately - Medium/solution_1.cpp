static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class FooBar {
private:
    int n;
    mutex m1, m2;

public:
    FooBar(int n)
        : n(n) {
        m1.lock();
        m2.lock();
    }

    void foo(function < void() > printFoo) {
        m1.unlock();
        for (int i = 0; i < n; i++) {
            m1.lock();
        	printFoo();
            m2.unlock();
        }
    }

    void bar(function < void() > printBar) {
        for (int i = 0; i < n; i++) {
            m2.lock();
        	printBar();
            m1.unlock();
        }
    }
};