class Foo {
    atomic < bool > isSecondAvailable = false;
    atomic < bool > isThirdAvailable  = false;
    
public:
    void first(function < void() > printFirst) {
        printFirst();
        
        isSecondAvailable.store(true);
    }

    void second(function < void() > printSecond) {
        while (bool mayIPass = !isSecondAvailable.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        printSecond();

        isThirdAvailable.store(true);
    }

    void third(function < void() > printThird) {
        while (bool mayIPass = !isThirdAvailable.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        printThird();
    }
};