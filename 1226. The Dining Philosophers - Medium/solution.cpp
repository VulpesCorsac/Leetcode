static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class DiningPhilosophers {
    std::mutex mutex;
    std::condition_variable cv;
    vector < int > isvalid;
    static constexpr int N = 5;

public:
    DiningPhilosophers() {
        isvalid.resize(N, 1);
    }

    void wantsToEat(int philosopher,
                    function < void() > pickLeftFork,
                    function < void() > pickRightFork,
                    function < void() > eat,
                    function < void() > putLeftFork,
                    function < void() > putRightFork) {
        {
            std::unique_lock < std::mutex > lock(mutex);
            cv.wait(lock, [this, philosopher]() { return isvalid[philosopher] && isvalid[(philosopher + 1) % N]; } );
            isvalid[philosopher] = isvalid[(philosopher + 1) % N] = 0;
            pickLeftFork(); 
            pickRightFork();
        }
        
        eat();
        
        {
            std::unique_lock < std::mutex > lock(mutex);
            putLeftFork(); 
            putRightFork();
            isvalid[philosopher] = isvalid[(philosopher + 1) % N] = 1;
            cv.notify_all();
        }
    }
};