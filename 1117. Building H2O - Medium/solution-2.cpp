static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class H2O {
    int cnt;
    mutex m;
    condition_variable cv;

public:
    H2O()
        : cnt(0) {
    }

    void hydrogen(function < void() > releaseHydrogen) {
        unique_lock < mutex > l(m);

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        cv.wait(l, [=] () { return (cnt < 2) ? true : false; } );
        releaseHydrogen();

        ++cnt;
        cv.notify_all();
    }

    void oxygen(function < void() > releaseOxygen) {
        unique_lock < mutex > l(m);

        // releaseOxygen() outputs "O". Do not change or remove this line.
        cv.wait(l, [=] () { return (cnt == 2) ? true : false; } );

        releaseOxygen();

        cnt = 0;
        cv.notify_all();
    }
};