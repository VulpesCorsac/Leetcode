static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class ZeroEvenOdd {
private:
    int n;
    mutex m0, m1, m2;

public:
    ZeroEvenOdd(int n) 
        : n(n) {
        m0.lock();
        m1.lock();
        m2.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function < void(int) > printNumber) {
        m0.unlock();
        
        for (int i = 1; i <= n; i++) {
            m0.lock();
            
            printNumber(0);
            
            if (i & 1) {
                m1.unlock();
            } else {
                m2.unlock();
            }
        }        
    }

    void odd(function < void(int) > printNumber) {
        for (int i = 1; i <= n; i += 2) {
            m1.lock();
            
            printNumber(i);
            
            m0.unlock();
        }
    }

    void even(function < void(int) > printNumber) {
        for (int i = 2; i <= n; i += 2) {
            m2.lock();
            
            printNumber(i);
            
            m0.unlock();
        }
    }
};