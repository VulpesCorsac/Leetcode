static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class H2O {
    mutex m_hydrogen, m_oxygen;
    int count;

public:
    H2O()
        : count(0) {
        m_hydrogen.lock();
        m_oxygen.lock();
        m_hydrogen.unlock();
    }

    void hydrogen(function < void() > releaseHydrogen) {
        m_hydrogen.lock();

        ++count;

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        if (count & 1){
            m_hydrogen.unlock();
        } else {
            m_oxygen.unlock();
        }
    }

    void oxygen(function < void() >  releaseOxygen) {
        m_oxygen.lock();

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        m_hydrogen.unlock();
    }
};